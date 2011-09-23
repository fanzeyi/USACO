/*
ID: fanzeyi1
LANG: C
TASK: subset
*/
/*
 * =====================================================================================
 *
 *       Filename:  subset.c
 *        Version:  1.0
 *        Created:  09/22/2011 06:03:33 AM
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

long long f[40][781]; 

int main(void) {
    FILE *fin = fopen("subset.in","r");
    FILE *fout = fopen("subset.out", "w");
    int i, j; 
    int n;
    int sum; 
    fscanf(fin, "%d", &n); 
    sum = (n * (n + 1))/2; 
    if(sum % 2 != 0) {
        fprintf(fout, "0\n"); 
        return 0; 
    }
    sum = sum / 2; 
    f[1][1] = 1; 
    f[1][0] = 1; 
    for( i = 2 ; i <= n ; i++ ) {
        for( j = 0 ; j <= sum ; j++ ) {
            if( j - i >= 0 ) {
                f[i][j] = f[i-1][j] + f[i-1][j-i]; 
            }else{
                f[i][j] = f[i-1][j]; 
            }
        }
    }
    fprintf(fout, "%lld\n", f[n][sum]/2); 
    return 0;
}
