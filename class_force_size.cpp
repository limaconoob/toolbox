#include <stdio.h>

#pragma pack(push, 1)
class Bonjour
{ public :
    unsigned a :1;
    unsigned b :1;
    unsigned c :1;
    unsigned d :1;
    unsigned e :1;
    unsigned f :1;
    unsigned g :1;
    unsigned h :1; };
#pragma pack(pop)

int main()
{ printf("BONJOUR::%lu\n", sizeof(Bonjour)); }
