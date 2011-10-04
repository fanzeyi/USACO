/*
ID: fanzeyi1
LANG: C
TASK: theme 
*/
/*
 * =====================================================================================
 *
 *       Filename:  theme.c
 *        Version:  1.0
 *        Created:  09/30/2011 03:06:07 PM
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

int music[5001]; 
int dp[2][5001]; 

inline int imax(int a, int b) {
    return a > b ? a : b; 
}

int main(void) {
    FILE *fin = fopen("theme.in","r");
    FILE *fout = fopen("theme.out", "w");
    int i, j; 
    int n;
    int max = 0; 
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d", &music[i]); 
    }
    for( i = n-1 ; i >= 0 ; i-- ) {
        for( j = 0 ; j < n ; j++ ) {
            if(i == j) {
                continue; 
            }
            if(i&1) {
                if(music[i] - music[j] == music[i+1] - music[j+1]) {
                    if(dp[0][j+1] + 1 > j - i) {
                        dp[1][j] = 1; 
                        continue; 
                    }
                    dp[1][j] = dp[0][j+1] + 1; 
                    if(dp[1][j] > max) {
                        max = dp[1][j]; 
                    }
                }else{
                    dp[1][j] = 1;
                }
            }else{
                if(music[i] - music[j] == music[i+1] - music[j+1]) {
                    if(dp[1][j+1] + 1 > j - i) {
                        dp[0][j] = 1; 
                        continue; 
                    }
                    dp[0][j] = dp[1][j+1] + 1; 
                    if(dp[0][j] > max) {
                        max = dp[0][j]; 
                    }
                }else{
                    dp[0][j] = 1;
                }
            }
        }
    }
    if(max >= 5) {
        fprintf(fout, "%d\n", max); 
    }else{
        fprintf(fout, "0\n"); 
    }
    return 0;
}
