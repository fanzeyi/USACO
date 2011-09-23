/*
ID: fanzeyi1
LANG: C
TASK: hamming
*/
/*
 * =====================================================================================
 *
 *       Filename:  hamming.c
 *        Version:  1.0
 *        Created:  09/22/2011 03:06:52 AM
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

/* 
 * x := (x and $55555555) + ((x shr 1) and $55555555); 
 * x := (x and $33333333) + ((x shr 2) and $33333333);
 * x := (x and $0F0F0F0F) + ((x shr 4) and $0F0F0F0F);
 * x := (x and $00FF00FF) + ((x shr 8) and $00FF00FF);
 * x := (x and $0000FFFF) + ((x shr 16) and $0000FFFF);
 */

int result[64] = {0};
int n, b, d; 

int count(x) {
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555); 
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333); 
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F); 
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF); 
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF); 
    return x; 
}

int check(int a, int cc) {
    int i; 
    for( i = 0 ; i < cc ; i++ ) {
        if(count(a^result[i]) < d) {
            return 0; 
        }
    }
    return 1; 
}

int main(void) {
    FILE *fin = fopen("hamming.in","r");
    FILE *fout = fopen("hamming.out", "w");
    int max[8] = {2, 4, 8, 16, 32, 64, 128, 256}; 
    int cc = 1; 
    int i; 
    fscanf(fin, "%d %d %d", &n, &b, &d); 
    fprintf(fout, "0"); 
    for( i = 1 ; cc < n && i < max[b-1] ; i++ ) {
        if(check(i, cc)) {
            if(cc % 10 != 0) {
                fprintf(fout, " "); 
            }else{
                fprintf(fout, "\n"); 
            }
            fprintf(fout, "%d", i);
            result[cc++] = i; 
        }
    }
    fprintf(fout, "\n"); 
    return 0;
}
