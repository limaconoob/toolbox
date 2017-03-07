
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Pony.hpp"

void ponyOnTheHeap(char *coucou)
{ Pony *pp;
  pp = new Pony();
  strcpy((*pp).nom, (char *)coucou);
  std::cout << (*pp).nom << std::endl; }

void ponyOnTheStack(char *coucou)
{ Pony pp;
  strcpy(pp.nom, coucou);
  std::cout << pp.nom << std::endl; }
