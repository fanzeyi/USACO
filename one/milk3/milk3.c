/*
ID: fanzeyi1
LANG: C
TASK: milk3 
*/
/*
 * =====================================================================================
 *
 *       Filename:  milk3.c
 *        Version:  1.0
 *        Created:  09/13/2011 05:15:24 PM
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

int A, B, C; 
int result[21] = {0}; 
int tree[22021] = {0}; 
int result_point = 0; 

void dfs(int a, int b, int c, int times) {
    if(tree[a+b*100+c*1000]){
        return; 
    }else{
        tree[a+b*100+c*1000] = 1; 
    }
    if(times == 29){
        return; 
    }
    /* Check */
    if(a == 0){
        result[c] = 1; 
    }
    /* c->b */
    if( b + c > B) {
        dfs(a, B, c - (B - b), times + 1); 
    }else{
        dfs(a, b + c, 0, times + 1); 
    }
    /* c->a */
    if( a + c > A) {
        dfs(A, b, c - (A - a), times + 1); 
    }else{
        dfs(a + c, b, 0, times + 1); 
    }
    /* a->b */
    if( a + b > B) {
        dfs(a - (B - b), B, c, times + 1); 
    }else{
        dfs(0, b + a, c, times + 1); 
    }
    /* a->c */
    if( a + c > C) {
        dfs(a - (C - c), b, C, times + 1); 
    }else{
        dfs(0, b, a + c, times + 1); 
    }
    /* b->a */
    if( b + a > A ) {
        dfs(A, b - (A - a), c, times + 1); 
    }else{
        dfs(a + b, 0, c, times + 1); 
    }
    /* b->c */
    if( b + c > C ) {
        dfs(a, b - ( C - c ), C, times + 1); 
    }else{
        dfs(a, 0, b + c, times + 1); 
    }
}

int main(void) {
    FILE *fin = fopen("milk3.in","r");
    FILE *fout = fopen("milk3.out", "w");
    int i; 
    int flag = 0; 
    fscanf(fin, "%d %d %d", &A, &B, &C); 
    dfs(0, 0, C, 0); 
    for( i = 0 ; i <= 20 ; i++ ) {
        if(flag && result[i]){
            fprintf(fout, " "); 
        }
        if(result[i]){
            flag = 1; 
            fprintf(fout, "%d", i); 
        }
    }
    fprintf(fout, "\n"); 
    return 0;
}
