/*
ID: fanzeyi1
LANG: C
TASK: zerosum
*/
/*
 * =====================================================================================
 *
 *       Filename:  zerosum.c
 *        Version:  1.0
 *        Created:  09/23/2011 10:21:26 AM
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
#define UNDEFINED 0
#define SPACE 1
#define PLUS 2
#define MINUS 3

int max; 
int number[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
int result[9] = {0}; 
FILE *fout; 

void dfs(int times) {
    if(times == max) {
        int i; 
        int now = 0; 
        int num = 0;  
        int prev = UNDEFINED; 
        for( i = 0 ; i < max ; i++ ) {
            if(result[i] == SPACE) {
                num = num * 10 + i + 1; 
                continue; 
            }
            if(result[i] == PLUS || result[i] == MINUS) {
                num = num * 10 + i + 1; 
                switch(prev) {
                    case UNDEFINED: now = num; break; 
                    case PLUS: now += num; break; 
                    case MINUS: now -= num; break; 
                }
                num = 0; 
                prev = result[i]; 
            }
        }
        num = num * 10 + i + 1; 
        switch(prev) {
            case UNDEFINED: return; 
            case PLUS: now += num; break; 
            case MINUS: now -= num; break; 
        }
        if(now == 0) {
            for( i = 0 ; i < max ; i++ ) {
                fprintf(fout, "%d", i+1); 
                switch(result[i]) {
                    case SPACE: fprintf(fout, " "); break; 
                    case PLUS: fprintf(fout, "+"); break; 
                    case MINUS: fprintf(fout, "-"); break; 
                }
            }
            fprintf(fout, "%d", max+1); 
            fprintf(fout, "\n"); 
        }
        return; 
    }
    result[times] = SPACE; 
    dfs(times+1); 
    result[times] = PLUS; 
    dfs(times+1); 
    result[times] = MINUS; 
    dfs(times+1); 
}

int main(void) {
    FILE *fin = fopen("zerosum.in","r");
    fout = fopen("zerosum.out", "w");
    fscanf(fin, "%d", &max); 
    max = max - 1; 
    dfs(0); 
    return 0;
}
