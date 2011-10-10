/*
ID: fanzeyi1
LANG: C
TASK: inflate
*/
/*
 * =====================================================================================
 *
 *       Filename:  inflate.c
 *        Version:  1.0
 *        Created:  10/10/2011 05:02:35 PM
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

inline int max(int a, int b) {
    return a > b ? a : b; 
}

int main(void) {
    FILE *fin = fopen("inflate.in","r");
    FILE *fout = fopen("inflate.out", "w");
    int m, n; 
    int i, j; 
    int cost[10001], value[10001]; 
    int f[10001];  // 
    fscanf(fin, "%d %d", &m, &n);
    for( i = 1 ; i <= n ; i++ ) {
        fscanf(fin, "%d %d", &value[i], &cost[i]); 
    }
    for( i = 1 ; i <= n  ; i++ ) {
        for( j = cost[i] ; j <= m ; j++ ) {
            f[j] = max(f[j], f[j-cost[i]] + value[i]); 
        }
    }
    fprintf(fout, "%d\n", f[m]); 
    return 0;
}
