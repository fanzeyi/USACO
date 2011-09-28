/*
ID: fanzeyi1
LANG: C
TASK: clocks 
*/
/*
 * =====================================================================================
 *
 *       Filename:  clocks.c
 *        Version:  1.0
 *        Created:  09/11/2011 10:06:59 PM
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
/*
 * A B C D E F G H I 
 * 0 1 2 3 4 5 6 7 8
 */

/*
 * A B C D E F G H I
 * 1 2 2 0 3 3 0 0 0 
 */

FILE *fout; 
FILE *fin; 
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
int used[9] = {0}; 
int result[27] = {0}; 
int flag = 0; 

int check(int *status) {
    int i; 
    for( i = 0 ; i < 9 ; i++ ) {
        if(status[i] != 0){
            return 0; 
        }
    }
    for( i = 0 ; i < 9 ; i++ ) {
        printf("%d ", status[i]); 
    }
    return 1; 
}

void dfs(int times, int *status) {
    int i; 
    int j; 
    if(flag){
        return; 
    }
    if(check(status)){
        for( i = 0 ; i < 4 ; i++ ) {
            if(result[i] == -1){
                break; 
            }
            if(i != 0){
                fprintf(fout, " "); 
            }
            fprintf(fout, "%d", result[i]); 
        }
        flag = 1; 
        return; 
    }
    if(times == 26){
        return; 
    }
    for( i = 0 ; i < 9 ; i++ ) {
        if(used[i] > 3) {
            continue; 
        }
        if(times != 0 && i < result[times-1] - 2) {
            continue; 
        }
        for( j = 0 ; j < 5 ; j++ ) {
            if(move[i][j] == -1){
                break; 
            }
            status[move[i][j]] += 1; 
            if(status[move[i][j]] == 4) {
                status[move[i][j]] = 0; 
            }
        }
        result[times] = i + 1; 
        used[i] = used[i] + 1; 
        dfs(times+1, status); 
        if(flag){
            return; 
        }
        result[times] = 0; 
        used[i] = used[i] - 1; 
        for( j = 0 ; j < 5 ; j++ ) {
            if(move[i][j] == -1){
                break; 
            }
            status[move[i][j]] -= 1; 
            if(status[move[i][j]] == -1) {
                status[move[i][j]] = 3; 
            }
        }
    }
}

int main(void) {
    fin = fopen("clocks.in","r");
    fout = fopen("clocks.out", "w");
    int clocks[9] = {0}; 
    int i;
    int a; 
    for( i = 0 ; i < 9 ; i++ ) {
        fscanf(fin, "%d", &a); 
        switch(a) {
            case 12: clocks[i] = 0; break; 
            case 3: clocks[i] = 1; break; 
            case 6: clocks[i] = 2; break; 
            case 9: clocks[i] = 3; break; 
        }
        printf("%d ", clocks[i]); 
    }
    printf("\n"); 
    dfs(0, clocks); 
    fprintf(fout, "\n"); 
    return 0;
}
