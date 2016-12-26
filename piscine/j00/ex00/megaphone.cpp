/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 07:52:54 by jpepin            #+#    #+#             */
/*   Updated: 2016/12/26 08:02:38 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int   main(int argc, char **argv)
{ if (argc <= 1)
  { std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; }
  else
  { argv++;
    while (*argv)
    { while (**argv)
      { if (**argv >= 'a' && **argv <= 'z')
        { **argv -= ' '; }
        std::cout << (**argv);
        (*argv)++; }
      argv++; }}
  std::cout << std::endl; }
