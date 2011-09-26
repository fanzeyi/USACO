/*
ID: fanzeyi1
LANG: C
TASK: money 
*/
/*
 * =====================================================================================
 *
 *       Filename:  money.c
 *        Version:  1.0
 *        Created:  09/26/2011 02:03:23 AM
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

int main(void) {
    FILE *fin = fopen("money.in","r");
    FILE *fout = fopen("money.out", "w");
    int v, n; 
    int i, j; 
    long long dp[10001] = {0}; 
    int money[26]; 
    fscanf(fin, "%d %d", &v, &n);
    for( i = 0 ; i < v ; i++ ) {
        fscanf(fin, "%d", &money[i]);
    }
    dp[0] = 1;
    for( i = 0 ; i < v ; i++ ) {
        for( j = 1 ; j <= n ; j++ ) {
            if(j - money[i] >= 0) {
                dp[j] = dp[j] + dp[j-money[i]]; 
            }
        }
    }
    fprintf(fout, "%lld\n", dp[n]); 
    return 0;
}
