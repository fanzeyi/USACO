/*
ID: fanzeyi1
LANG: C
TASK: clocks 
*/
/*
 * =====================================================================================
 *
 *       Filename:  clocks1.c
 *        Version:  1.0
 *        Created:  09/12/2011 01:22:26 PM
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

FILE *fin; 
FILE *fout; 
int flag = 0; 
int result[27] = {0}; 
int used[9] = {0}; 
int move[9][5] = {
    {0, 1, 3, 4, -1},  // ABDE
    {0, 1, 2, -1, -1},  // ABC
    {1, 2, 4, 5, -1}, // BCEF
    {0, 3, 6, -1, -1}, // ADG
    {1, 3, 4, 5, 7}, // BDEFH
    {2, 5, 8, -1, -1}, // CFI
    {3, 4, 6, 7, -1}, // DEGH
    {6, 7, 8, -1, -1}, // GHI
    {4, 5, 7, 8, -1} // EFHI
}; 


void print_status(int *status) {
    int i; 
    for( i = 0 ; i < 9 ; i++ ) {
        printf("%d ", status[i]); 
    }
    printf("\n");     
}

void optimize(int *status) {
    int i; 
    for( i = 0 ; i < 9 ; i++ ) {
        if(status[i] == 4) {
            status[i] = 0; 
            continue; 
        }
        if(status[i] == -1) {
            status[i] = 3; 
        }
    }
}

int check(int *status){
    int i; 
    for( i = 0 ; i < 9 ; i++ ) {
        if(status[i] != 0) {
            return 0; 
        }
    }
    return 1; 
} 

void dfs(int times, int *status){
    if(times == 28) {
        return; 
    }
    if(flag) {
        return; 
    }
    int i; 
    int j; 
    if(check(status)) {
        for( i = 0 ; i < 27 ; i++ ) {
            if(result[i] == 0){
                break; 
            }
            if(i != 0){
                fprintf(fout, " "); 
            }
            fprintf(fout, "%d", result[i]); 
        }
        flag = 1; 
    }
    for( i = 0 ; i < 9 ; i++ ) {
        if(used[i] == 3){
            continue; 
        }
        if(times != 0 && result[times-1] - 1 > i){
            continue; 
        }
        for( j = 0 ; j < 5 ; j++ ) {
            if(move[i][j] == -1){
                break; 
            }
            status[move[i][j]] += 1; 
        }
        optimize(status); 
        result[times] = i + 1; 
        used[i] = used[i] + 1; 
        dfs(times+1, status); 
        used[i] = used[i] - 1; 
        result[times] = 0; 
        for( j = 0 ; j < 5 ; j++ ) {
            if(move[i][j] == -1) {
                break; 
            }
            status[move[i][j]] -= 1; 
        }
        optimize(status); 
    }
}

int main(void) { 
    int i; 
    int status[9]; 
    int a; 
    fin = fopen("clocks.in","r");
    fout = fopen("clocks.out", "w"); 
    for( i = 0 ; i < 9 ; i++ ) {
        fscanf(fin, "%d", &a); 
        switch(a) {
            case 12: status[i] = 0; break; 
            case 3: status[i] = 1; break; 
            case 6: status[i] = 2; break; 
            case 9: status[i] = 3; break; 
        }
    }
    dfs(0, status); 
    fprintf(fout, "\n"); 
    return 0;
}
