#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n = 5;
    int m = 6;
    printf("a : %d, b : %d", n, m);
    swap(&n, &m);
    printf("\na : %d, b : %d\n", n, m);
}