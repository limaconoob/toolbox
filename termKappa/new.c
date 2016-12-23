/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:11:09 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/16 09:38:44 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <sys/types.h>
#include <stdio.h>

struct consolefontdesc {
  unsigned short charcount; /* characters in font (256 or 512) */
  unsigned short charheight;  /* scan lines per character (1-32) */
  char *chardata;   /* font data in expanded form */
};

int main(void)
{
  struct consolefontdesc *coucou;

//  printf("%d\n", ioctl(0, 0x4B6B, coucou));
  printf("%d\n", ioctl(0, 0x4B30));
//  printf("%d, %d, %s\n", coucou->charcount, coucou->charheight, coucou->chardata);
}
