/*
ID: fanzeyi1
LANG: C
TASK: sprime 
*/
/*
 * =====================================================================================
 *
 *       Filename:  sprime.c
 *        Version:  1.0
 *        Created:  09/16/2011 11:06:54 AM
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
#include <math.h>

int Prime(int a){
    int i; 
    int max = sqrt(a);
    for( i = 2 ; i <= max ; i++ ) {
        if(a % i == 0){
            return 0; 
        }
    }
    return 1; 
}

void dfs(int num, int times, int n, \
         FILE *fout) {
    if(times == n){
        fprintf(fout, "%d\n", num); 
    }
    if(Prime(num*10 + 1)){ 
        dfs(num*10 + 1, times+1, n, fout); 
    }
    if(Prime(num*10 + 3)){
        dfs(num*10 + 3, times+1, n, fout); 
    }
    if(Prime(num*10 + 7)){
        dfs(num*10 + 7, times+1, n, fout); 
    }
    if(Prime(num*10 + 9)){
        dfs(num*10 + 9, times+1, n, fout); 
    }
}

int main(void)
{
    FILE *fin = fopen("sprime.in","r");
    FILE *fout = fopen("sprime.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    if(n == 1){
        fprintf(fout, "2\n3\n5\n7"); 
        return 0; 
    }
    dfs(2, 1, n, fout); 
    dfs(3, 1, n, fout); 
    dfs(5, 1, n, fout); 
    dfs(7, 1, n, fout); 
    return 0;
}
