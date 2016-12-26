/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 08:31:39 by jpepin            #+#    #+#             */
/*   Updated: 2016/12/26 11:13:04 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "repertoire.h"

int main(void)
{ Repertoire<std::string> rep;
  std::string input;
  while (true)
  { std::getline(std::cin, input);
    if (std::cin.fail())
    { std::cout << "Erreur dans la lecture de l'entrée standard" << std::endl;
      break; }
    else if (!input.compare(0, 4, "EXIT") && input.size() == 4)
    { std::cout << "Sortant du programme repertoire" << std::endl;
      break; }
    else if (!input.compare(0, 4, "ADD ") && input.size() > 4)
    { rep.Add(&(input[4])); }
    else if (!input.compare(0, 6, "SEARCH") && input.size() == 6 && rep.Aflag())
    { rep.Display(); }
    else if (!input.compare(0, 7, "SEARCH ") && input.size() > 7)
    { rep.Search(&(input[7])); }
    else
    { std::cout << input << ": Commande introuvable." << std::endl; }}}
