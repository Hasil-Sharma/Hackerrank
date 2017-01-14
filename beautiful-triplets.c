#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int search_num(int *, int, int, int);

int main() {
    int n,d, *array, i, count, flag;
    scanf("%d %d", &n, &d);
    array = (int*)malloc(n*sizeof(int));
    
    for(i = 0; i < n; i++) scanf("%d", &array[i]);
    
    for(i = 0, count = 0; i < n; i++){
        flag = search_num(array, 0, n - 1, array[i] + d);
        flag = (flag) ? search_num(array, 0, n - 1, array[i] + 2*d) : 0;
        count += (flag) ? 1 : 0;
    }
    
    printf("%d\n", count);
    
    return 0;
}

int search_num(int * array, int lower, int upper, int value){
    int mid = lower + (upper - lower)/2;
    if (lower > upper) return 0;
    else if(array[mid] == value) return 1;
    else if(array[mid] > value) return search_num(array, lower, mid - 1, value);
    else if(array[mid] < value) return search_num(array, mid + 1, upper, value);
    return 0;
}

