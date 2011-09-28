/*
ID: fanzeyi1
LANG: C
TASK: numtri 
*/
/*
 * =====================================================================================
 *
 *       Filename:  numtri.c
 *        Version:  1.0
 *        Created:  09/13/2011 06:54:46 PM
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

int main(void)
{
    FILE *fin = fopen("numtri.in","r");
    FILE *fout = fopen("numtri.out", "w");
    int n;
    int i, j; 
    int **Tower;
    int **dp; 
    fscanf(fin, "%d", &n);
    Tower = (int**)malloc(sizeof(int*) * n); 
    dp = (int**)malloc(sizeof(int*) * n); 
    for( i = 0 ; i < n ; i++ ) {
        Tower[i] = (int*)calloc(n, sizeof(int)); 
        dp[i] = (int*)calloc(n, sizeof(int)); 
        for( j = 0 ; j <= i ; j++ ) {
            fscanf(fin, "%d ", &Tower[i][j]); 
        }
    }
    for( i = 0 ; i < n ; i++ ) {
        dp[n-1][i] = Tower[n-1][i]; 
    }
    for( i = n - 2 ; i >= 0 ; i-- ) {
        for( j = 0 ; j <= i ; j++ ) {
            if(dp[i+1][j] > dp[i+1][j+1]){
                dp[i][j] = Tower[i][j] + dp[i+1][j]; 
            }else{
                dp[i][j] = Tower[i][j] + dp[i+1][j+1]; 
            }
        }
    }
    fprintf(fout, "%d\n", dp[0][0]); 
    return 0;
}
