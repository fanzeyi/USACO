/*
ID: fanzeyi1
LANG: C
TASK: nocows
*/
/*
 * =====================================================================================
 *
 *       Filename:  nocows.c
 *        Version:  1.0
 *        Created:  09/23/2011 08:42:22 AM
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

int f[202][101]; 

int main(void) {
    FILE *fin = fopen("nocows.in","r");
    FILE *fout = fopen("nocows.out", "w");
    int n, k;
    int i, j, l;
    int result; 
    fscanf(fin, "%d %d", &n, &k); 
    if(n % 2 == 0) {
        fprintf(fout, "0\n"); 
        return 0; 
    }
    for( i = 0 ; i < 202 ; i++ ) {
        for( j = 0 ; j < 101 ; j++ ) {
            f[i][j] = 0; 
        }
    }
    for( i = 1 ; i <= k ; i++ ) {
        f[1][i] = 1; 
    }
    for( i = 1 ; i <= n ; i++ ) {
        if( i % 2 == 1 ) {
            for( j = 1 ; j <= k ; j++ ) {
                for( l = 1 ; l < i - 1 ; l++ ) {
                    if( l % 2 == 1) {
                        f[i][j] += f[i-l-1][j-1] * f[l][j-1]; 
                        f[i][j] %= 9901; 
                    }
                }
            }
        }
    }
    result = f[n][k] - f[n][k-1]; 
    if(result < 0) {
        result = result + 9901; 
    }
    result = result % 9901; 
    fprintf(fout, "%d\n", result); 
    return 0;
}
