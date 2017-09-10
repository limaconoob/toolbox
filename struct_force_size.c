#include <stdio.h>

struct __attribute__((__packed__))
       __attribute__((aligned(1))) salut
{ unsigned i :1;
  unsigned k :1;
  unsigned o :1;
  unsigned p :1;
  unsigned m :1;
  unsigned j :1; } salut;

struct coucou
{ unsigned i :1;
  unsigned k :1;
  unsigned o :1;
  unsigned p :1;
  unsigned m :1;
  unsigned j :1; } coucou;

unsigned main(void)
{ printf("SALUT::%lu, COUCOU::%lu\n", sizeof(salut), sizeof(coucou)); }
