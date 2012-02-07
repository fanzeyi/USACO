
/*
 * =====================================================================================
 * 
 *       Filename:  sorttest.cc
 *        Created:  01/28/2012 11:28:23 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int *num; 
int n; 

inline int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b; 
}

inline int next_int() {
    char c;
    while (!isdigit(c = getchar())) ;
    int res = c - '0';
    while (isdigit(c = getchar())) {
        res = res * 10 + c - '0';
    }
    return res;
}

int main() {
    int i; 
    freopen("sorttest.in", "r", stdin); 
    freopen("sorttest.out", "w", stdout); 
    fscanf(stdin, "%d", &n); 
    num = (int*)calloc(n, sizeof(int)); 
    for(i = 0; i < n; i++) {
        num[i] = next_int(); 
    }
    qsort(num, n, sizeof(int), cmp); 
    for(i = 0; i < n - 1; i++) {
        fprintf(stdout, "%d ", num[i]); 
    }
    fprintf(stdout, "%d\r\n", num[i-1]);
    return 0; 
}
