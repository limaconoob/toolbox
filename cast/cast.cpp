#include <iostream>
#include "lib.h"

void start(t_lbstat *lib, int *coucou)
{ (void)lib;
  int i = 0;
  while (i < 5)
  { coucou[i] = 97;
    i += 1; }}

int main(void)
{ t_lbstat *lib;
  int coucou[5];
  start(lib, coucou);
  int i = 0;
  while (i < 5)
  { std::cout << static_cast<char>(coucou[i]);
    i += 1; }
  std::cout << "\n"; }
