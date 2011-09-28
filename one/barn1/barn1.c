/*
ID: fanzeyi1
LANG: C
TASK: barn1 
*/
/*
 * =====================================================================================
 *
 *       Filename:  barn1.c
 *        Version:  1.0
 *        Created:  08/30/2011 09:44:47 PM
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

void MarkTheMostZeroArea(int *array,int start, int n) {
    int i; 
    int len = 0; 
    int max[2] = {0}; 
    for( i = start ; i < n ; i++ ) {
        if(array[i] == 1 || array[i] == -1) {
            if(len > max[0]) {
                max[0] = len; 
                max[1] = i - len; 
            }
            len = 0; 
            continue; 
        }
        if(array[i] == 0) { 
            len = len + 1; 
        }
    }
    if(len > max[0]) {
        max[0] = len; 
        max[1] = i - len; 
    }
    for( i = max[1] ; array[i] != 1 ; i++ ){
        array[i] = -1; 
    }
//    printf("\n%d %d\n", max[0], max[1]); 
}

void PrintArray(int *array, int start, int n) {
    int i; 
    for( i = start ; i < n ; i++ ){
        printf("%d ", array[i]); 
    }
}

int main(void)
{
    FILE *fin = fopen("barn1.in","r");
    FILE *fout = fopen("barn1.out", "w");
    int m, s, c; 
    int *cow; 
    int i; 
    int a; 
    int max = 0; 
    int min = 0x7FFFFFF; 
    int count = 0; 
    fscanf(fin, "%d %d %d", &m, &s, &c); 
    s = s + 1; 
    cow = (int*)calloc(s, sizeof(int)); 
    for( i = 0 ; i < s ; i++ ){
        fscanf(fin, "%d", &a); 
        cow[a] = 1;
        if(a > max) {
            max = a; 
        }
        if(a < min) {
            min = a; 
        }
    }
    max = max + 1; 
//    PrintArray(cow, 0, s); 
    for( i = 1 ; i < m ; i++ ) {
        MarkTheMostZeroArea(cow, min, max); 
//        PrintArray(cow, min, max); 
    }
    for( i = min ;  i < max ; i++ ){
        if(cow[i] != -1) {
            count = count + 1;
        }
    }
    fprintf(fout, "%d\n", count); 
    return 0;
}
