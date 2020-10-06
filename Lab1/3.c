#include <stdio.h>
typedef unsigned char byte;

int main(){
    unsigned int x = 0x20000718;
    printf("%lu", sizeof(unsigned int));
    printf("\n%lu", sizeof(unsigned char));
    byte a, b, c, d;
    a = x & 0xFF;
    b = (x >> 8) & 0xFF;
    c = (x >> 16) & 0xFF;
    d = (x >> 24) & 0xFF;
    printf("\n%x\n", a);
    printf("%x\n", b);
    printf("%x\n", c);
    printf("%x\n", d);
    return 0;
}