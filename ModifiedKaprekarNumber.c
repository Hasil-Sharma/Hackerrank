#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define int_in(n) scanf("%d", &n)
#define debug(i,n) //printf("%d : %d\n", i, n)
int check(int);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int p, q, i, flag;
    int_in(p);
    int_in(q);
    for(i = p, flag = 0; i <= q; i++){
        debug(1, i);
        if(check(i)){
            flag = 1;
            printf("%d ", i);
        }
    }
    if(flag == 0) printf("INVALID RANGE");
    
    return 0;
}

int check(int n){
    int num_digits = (int) log10(n) + 1;
    debug(2, num_digits);
    int l,r;
    int base = pow(10, num_digits);
    long long int sqr = (long long int)n;
    sqr *= sqr;
    
    l = sqr/base;
    r = sqr%base;
    
    return (l + r == n) ? 1 : 0;
    
}
