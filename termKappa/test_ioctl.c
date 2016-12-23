/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ioctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 08:21:43 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/16 09:06:19 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdlib.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <errno.h>
//#include <sys/hft.h>


/*
 *   Signal catching routine.
 *   */

sigcatch(sig)
  int sig;
{
  int i;
  signal(sig, sigcatch);
}


/* 
 *   The following macro is used to convert an integer to a 1 byte character.
 *   */

#define INT_TO_CHAR(s) (char) s

#define STDIN   0

main(argc, argv)
  int argc;
  char  *argv[];
{

  int fontid;
  int fildes;               /* /dev/tty file descriptor */
  int i;
  int rc1, rc2;             /* return codes */
  char *errstring;            /* string used for error messages */
  struct termio oldterm, newterm;     /* tty flags saved and restored */
  struct hftgetid hftgetid;       /* get id structure */
  struct hffont cfont;          /* font change structure */
  char *font_ptr;             /* ptr for stepping through fonts */

  if (argc < 2 || !isdigit(*argv[1]))
  {
    printf("\n   usage: chgfont FONTID1, ...[FONTID2, FONTID3, FONTID4]\n");
    printf("   where FONTID1 (and the other optional font id's) are\n"); 
    printf("   valid font id's as returned from the AIX lsfont command\n");
    return(-1);
  }

  /*
   *    Catch the change-window-size signal, which is issued whenever
   *        the window size is changed (the hft issues it when the display
   *            window sizes differ).
   *              */

  signal(SIGWINCH, sigcatch);

  /*
   *    Issue an HFTGETID ioctl to determine if this command is being
   *        issued from an HFT.
   *          */

  rc1 = ioctl(STDIN, HFTGETID, &hftgetid);
  if ( rc1 != 0 )
  {
    error_msg("   The HFTGETID ioctl failed", rc1, errno);
    return(-1);
  }

  /*
   *    Ensure that a valid virtual terminal id was returned from the 
   *        HFTGETID ioctl.
   *          */

  rc1 = hftgetid.hf_chan;
  if ( rc1 < 0 )
  {
    printf("   Invalid virtual terminal id returned from HFTGETID ioctl\n");
    return(-1);
  }

  sscanf(argv[1], "%x", &fontid);

  /* 
   *    Initialize the change font structure that we will pass to the HFT.
   *      */

  cfont.hf_intro[0] = HFINTROESC;       /* escape character */
  cfont.hf_intro[1] = HFINTROLBR;       /* left bracket */
  cfont.hf_intro[2] = HFINTROEX;        /* lower case x */
  cfont.hf_intro[3] = '\0';         /* null character */
  cfont.hf_intro[4] = '\0';         /* null character */
  cfont.hf_intro[5] = '\0';         /* null character */
  cfont.hf_intro[6] = INT_TO_CHAR(sizeof(struct hffont) - 3);
  cfont.hf_intro[7] = HFFONTH;        /* operation type=font: */
  cfont.hf_intro[8] = HFFONTL;
  cfont.hf_sublen = 2;
  cfont.hf_subtype = 0;


  /*
   *    There is a primary font and there are 7 alternate fonts, eight 
   *        fonts in all. This program will allow the primary and first three
   *            alternates to be set from the command line. All 8 fonts are ini-
   *                tialized to the primary font. If there are any more command
   *                    line arguments besides the primary font, the first through
   *                        third alternate fonts will be set appropriately.
   *                          */

  for ( font_ptr = &cfont.hf_primary[0]; font_ptr <= &cfont.hf_alt7[0];
      font_ptr++ )
  {
    font_ptr[0] = 0;
    font_ptr[1] = fontid;
  }


  /*
   *    Get font id of 1st alternate font from 2nd argument.
   *      */


  if ( argc >= 3  &&  isdigit(argv[2]) )
  {
    sscanf(argv[2], "%x", &fontid);
    cfont.hf_alt1[0] = 0;
    cfont.hf_alt1[1] = fontid;
  }

  /*
   *    Get font id of 2nd alternate font from 3rd argument.
   *      */


  if ( argc >= 4  &&  isdigit(argv[3]) )
  {
    sscanf(argv[3], "%x", &fontid);
    cfont.hf_alt2[0] = 0;
    cfont.hf_alt2[1] = fontid;
  }


  /*
   *    Get font id of 3rd alternate font from 2nd argument.
   *      */


  if ( argc > 4  &&  isdigit(argv[4]) )
  {
    sscanf(argv[4], "%x", &fontid);
    cfont.hf_alt3[0] = 0;
    cfont.hf_alt3[1] = fontid;
  }


  /*
   *    First turn off output processing on the current terminal so we
   *        can write safely to the HFT. We get the current tty configuration
   *            and save it in oldterm, then copy it to newterm and modify it to 
   *                turn off output processing. After writing the font change escape 
   *                    sequence to the HFT, we restore the old tty settings.
   *                      */

  rc1 = ioctl(STDIN, TCGETA, &oldterm);
  if ( rc1 != 0 )
  {
    error_msg("\n   TCGETA ioctl failed", rc1, errno);
    return(-1);
  }

  newterm = oldterm;
  newterm.c_oflag = ~OPOST;
  rc1 = ioctl(STDIN, TCSETAW, &newterm);
  if ( rc1 != 0 )
  {
    error_msg("\n   TCSETAW ioctl failed", rc1, errno);
    return(-1);
  }


  /*
   *    Open the currently active hft terminal to handle the change
   *        font write system call.
   *          */

  fildes = open( "/dev/tty", O_RDWR );

  if (fildes < 0)
  {
    errstring = "\n   The open system call to /dev/tty failed";
    error_msg(errstring, fildes, errno);
    exit(-1);
  }



  /*
   *    Write the font structure to the terminal.
   *      */


  rc1 = write(fildes, &cfont, sizeof(cfont));

  if (rc1 != sizeof(struct hffont))
  {
    errstring = "   The change font write call to /dev/hft failed";
    error_msg(errstring, rc1, errno);

    /*
     *       If the errno from the change font write call is
     *               equal to EIO, then issue a "query error" ioctl
     *                     to the HFT to find out more detail on the  exact
     *                           cause of the error.        
     *                                 The explanations for the return codes from the  
     *                                         "query error" ioctl are contained in the HFT
     *                                               documentation.
     *                                                  */

    if (errno == EIO)
    {
      rc1 = ioctl(fildes, HFQERROR, &rc2);
      if ( rc1 != 0 )
      {
        errstring = "   The HFQERROR ioctl failed";
        error_msg(errstring, rc1, errno);
      }
      else
      {
        printf("\n   The HFT error code is = %d\n", rc2);
        printf("   A complete description of the error ");
        printf("codes is contained in the HFT\n");
        printf("   documentation.\n\n");
      }
    }

  }

  rc1 = ioctl(STDIN, TCSETAW, &oldterm);      /* restore term parameters */
  if ( rc1 != 0 )
  {
    error_msg("\n   TCSETAW ioctl failed", rc1, errno);
    return(-1);
  }

  return(rc1);
}


/*
 *   Error message routine.
 *   */

error_msg(errstring, return_code, error_num)
  char  *errstring;
  int   return_code;
  int   error_num;
{
  printf("%s\n", errstring);
  printf("   The return code was %d\n", return_code);
  printf("   The error number errno = %d\n", error_num);
}

/*
   int main(void)
   {
   struct termios  term;

   if (tcgetattr(0, &term) == -1)
   return (0);
   term.c_lflag ^= ~(ONLRET);
   term.c_cc[VMIN] = 1;
   term.c_cc[VTIME] = 0;
   if (tcsetattr(0, TCSADRAIN, &term) == -1)
   return (0);
//    char *font = "Arial";
//    ret_val = ioctl(1, SETFONT, font); 
}
*/
