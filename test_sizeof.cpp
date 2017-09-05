class A
{ public:
    bool a;
    bool za;
    bool ea;
    bool ra;
    bool ta;
    bool ya;
    bool ua;
    bool oa;
    bool opa;
    bool b;
    bool c;
    bool d;
    A(); };

A::A(void)
{ a = 0;
  za = 0;
  ea = 0;
  ra = 0;
  ta = 0;
  ya = 0;
  ua = 0;
  oa = 0;
  opa = 0;
  b = 0;
  c = 0;
  d = 0; }

struct B
{ unsigned a :1;
  unsigned ab :1;
  unsigned zb :1;
  unsigned eb :1;
  unsigned rb :1;
  unsigned tb :1;
  unsigned yb :1;
  unsigned ub :1;
  unsigned ib :1;
  unsigned ob :1;
  unsigned c :1;
  unsigned d :1; };

#include <stdio.h>
int main(void)
{ printf("A::%ld B::%ld\n", sizeof(A), sizeof(B));
  A bonjour;
  B coucou;
  coucou.a = 0;
  coucou.ab = 0;
  coucou.zb = 1;
  coucou.eb = 1;
  coucou.rb = 1;
  coucou.tb = 1;
  coucou.yb = 1;
  coucou.ub = 1;
  coucou.ib = 1;
  coucou.ob = 1;
  coucou.c = 1;
  coucou.d = 1;
  printf("A::%ld B::%ld\n", sizeof(bonjour), sizeof(coucou));
  
}
