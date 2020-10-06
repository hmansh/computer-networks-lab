#include <stdio.h>
#include <string.h>
typedef unsigned char byte;

struct pkt{
    byte ch1;
    byte ch2[2];
    byte ch3;
};

void printDetails(struct pkt *number){
    printf("%x\n", number->ch1);
    printf("%x\n", number->ch2[0]);
    printf("%x\n", number->ch2[1]);
    printf("%x\n", number->ch3);
};

int main(){
    unsigned int x = 0x12345678;
    struct pkt number;
    number.ch1 = x & 0xFF;
    number.ch2[0] = (x >> 8) & 0xFF;
    number.ch2[1] = (x >> 16) & 0xFF;
    number.ch3 = (x >> 24) & 0xFF;
    printDetails(&number);
    return 0;
}