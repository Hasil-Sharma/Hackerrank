#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int length, row, column, i, j;
    
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
    
    length = strlen(s);
    
    row = sqrt(length);
    column = sqrt(length) + 1;
    
    column = (row*row >= length) ? row : column;
    
    for(i = 0; i < column; i++){
        for(j = i; j < length; j += column )
            printf("%c", s[j]);
        printf(" ");
    }
    
    return 0;
}

