/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:30:51 by jpepin            #+#    #+#             */
/*   Updated: 2016/11/04 01:01:56 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/rust.h"
#include <stdio.h>

i32 main()
{ mut i32 x;    //Mut int
  let u8 y = 0; //Const char
  mut _ *z;     //Void*
  x = 0;
  x += 1;
  // y += 1;    //Echec : Const assignation
  // z += 1;    //Echec : Void* assignation
  println("x::%d, y::%d\n", x, y); }
