
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
    else if (!rep.Sflag())
    { rep.Next(input); }
    else if (!rep.Aflag())
    { rep.Search(input); }
    else if (!input.compare(0, 3, "ADD") && input.size() == 3 && rep.Sflag())
    { rep.Add(); }
    else if (!input.compare(0, 6, "SEARCH") && input.size() == 6 && rep.Aflag())
    { rep.Display(); }
    else
    { std::cout << input << ": Commande introuvable." << std::endl; }}}
