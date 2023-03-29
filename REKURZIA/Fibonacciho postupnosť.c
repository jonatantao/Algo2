#include <stdio.h>
#include <stdlib.h>

long long fib(int);

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("%d. clen Fibonacciho postupnosti ma hodnotu = %lld\n", n, fib(n));
    return 0;
}


long long fib(int n){
    printf("pocitam hodnotu pre n = %d\n",n);
    if(n < 2) return 1;
    return fib(n-1)+fib(n-2);
}