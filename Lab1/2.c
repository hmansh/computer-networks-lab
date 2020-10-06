#include <stdio.h>
int main()
{
    unsigned int i = 1;
    char *c = (char *)&i;
    if (*c){
        printf("%c - ", *c);
        printf("Little endian\n");
    }
    else{
        printf("%c - ", *c);
        printf("Big endian\n");
    }
    return 0;
}