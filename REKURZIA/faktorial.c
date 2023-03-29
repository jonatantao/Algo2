#include <stdio.h>
#include <stdlib.h>

long long fakt(int);

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("%d! = %lld\n", n, fakt(n));
    return 0;
}


long long fakt(int n){
    printf("pocitam hodnotu pre n = %d\n",n);
    if(n < 1) return 1;
    return n * fakt(n-1);
}