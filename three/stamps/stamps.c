/*
ID: fanzeyi1
LANG: C
TASK: stamps 
*/
/*
 * =====================================================================================
 *
 *       Filename:  stamps.c
 *        Version:  1.0
 *        Created:  10/12/2011 06:03:41 PM
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

int k, n; 
int stamp[50]; 
int f[2000001]; 

inline int min(int a, int b) {
    return a > b ? b : a; 
}

int main(void) {
    FILE *fin = fopen("stamps.in","r");
    FILE *fout = fopen("stamps.out", "w");
    int i, j; 
    fscanf(fin, "%d %d", &k, &n);
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d", &stamp[i]); 
    }
    f[0] = 0; 
    for( i = 1 ; i < 2000001 ; i++ ) {
        f[i] = 0x7FFFFFFF; 
        for( j = 0 ; j < n ; j++ ) {
            if(stamp[j] <= i) {
                f[i] = min(f[i], f[i-stamp[j]] + 1); 
            }
        }
        if(f[i] > k) {
            break; 
        }
    }
    fprintf(fout, "%d\n", i - 1); 
    return 0;
}
