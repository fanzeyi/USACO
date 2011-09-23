/*
ID: fanzeyi1
LANG: C
TASK: sort3 
*/
/*
 * =====================================================================================
 *
 *       Filename:  sort3.c
 *        Version:  1.0
 *        Created:  09/21/2011 08:29:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Zeray Fan, fanzeyi1994[at]gmail.com
 *        Company:  http://www.fanhe.org/
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *i, int *j) {
    int t = *i;
    *i = *j;
    *j = t;
}

int main(void) {
    FILE *fin = fopen("sort3.in","r");
    FILE *fout = fopen("sort3.out", "w");
    int n;
    int i, j, k; 
    int *number; 
    int c1 = 0, c2 = 0, c3 = 0; 
    int count = 0; 
    fscanf(fin, "%d", &n); 
    number = (int*)calloc(n, sizeof(int)); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d", &number[i]); 
        switch(number[i]) {
            case 1: c1 = c1 + 1; break; 
            case 2: c2 = c2 + 1; break; 
            case 3: c3 = c3 + 1; break; 
        }
    }
    j = c1; 
    k = c1 + c2; 
    for( i = 0 ; i < c1 ; i++ ) {
        if(number[i] == 2) {
            for( ; j < n ; j++ ) {
                if(number[j] == 1) {
                    swap(&number[i], &number[j]); 
                    count = count + 1; 
                    break; 
                }
            }
        }else if(number[i] == 3) {
            for( ; k < n ; k++ ) {
                if(number[k] == 1) {
                    swap(&number[i], &number[j]); 
                    count = count + 1; 
                    break; 
                }
            }
            
        }
    }
    j = c1 + c2; 
    for( i = c1 ; i < c1 + c2 ; i++ ) {
        if(number[i] != 2) {
            for( ; j < n ; j++ ) {
                if(number[j] == 2) {
                    swap(&number[i], &number[j]); 
                    count = count + 1; 
                    break; 
                }
            }
        }
    }
    fprintf(fout, "%d\n", count); 
    return 0;
}
