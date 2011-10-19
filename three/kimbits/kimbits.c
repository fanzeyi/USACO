/*
ID: fanzeyi1
LANG: C
TASK: kimbits
*/
/*
 * =====================================================================================
 *
 *       Filename:  kimbits.c
 *        Version:  1.0
 *        Created:  10/19/2011 03:08:50 PM
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

FILE *fout; 
unsigned int f[32][32];  // 长度为 i 的, 1 的数量少于等于 j 的数目

void output(int n, int l, int i) {
    if(!n) {
        return; 
    }
    long long m; 
    m = f[n-1][l]; 
    if(m <= i) {
        fprintf(fout, "1"); 
        output(n-1, l-1, i-m); 
    }else{
        fprintf(fout, "0"); 
        output(n-1, l, i); 
    }
}

int main(void) {
    FILE *fin = fopen("kimbits.in","r");
    unsigned int n, l, p; 
    unsigned int i, j; 
    fout = fopen("kimbits.out", "w");
    fscanf(fin, "%u %u %u", &n, &l, &p);
    for( i = 0 ; i <= n ; i++ ) {
        f[i][0] = 1; 
    }
    for( i = 0 ; i <= l ; i++ ) {
        f[0][i] = 1; 
    }
    for( i = 1 ; i <= n ; i++ ) {
        for( j = 1 ; j <= l ; j++ ) {
            f[i][j] = f[i-1][j] + f[i-1][j-1]; 
        }
    }
    output(n, l, p-1);
    fprintf(fout, "\n"); 
    return 0;
}
