/*
ID: fanzeyi1
LANG: C
TASK: holstein
*/
/*
 * =====================================================================================
 *
 *       Filename:  holstein.c
 *        Version:  1.0
 *        Created:  09/21/2011 09:05:00 AM
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

int v, g; 
int vita[26]; 
int feed[16][26]; 
int now[26]; 
int choose[26]; 
int used[16];
int result[16]; 
int final_result[16]; 
int count = 0x7FFFFFFF; 

void solve(int times) {
    int flag = 1; 
    if(times < count) {  
        int i; 
        for( i = 0 ; i < v ; i++ ) {
            if(now[i] < vita[i]) {
                flag = 0; 
                break; 
            }
        } // Check Result
        if(flag) { 
            if(times == count && result[0] >= final_result[0]) {
                return; 
            }
            for( i = 0 ; i < v ; i++ ) {
                choose[i] = now[i]; 
            } // Make choose  ==  now; 
            for( i = 0 ; i < times ; i++ ) {
                final_result[i] = result[i]; 
            }
            count = times; 
            return; 
        }
    }else{
        return; 
    }
    int i, j; 
    for( i = 0 ; i < g ; i++ ) {
        if(used[i]) {
            continue; 
        }
        for( j = 0 ; j < v ; j++ ) {
            now[j] = now[j] + feed[i][j]; 
        }
        result[times] = i+1;
        used[i] = 1; 
        solve(times+1); 
        result[times] = 0; 
        used[i] = 0; 
        for( j = 0 ; j < v ; j++ ) {
            now[j] = now[j] - feed[i][j]; 
        }
    }
    return; 
}

int main(void) {
    FILE *fin = fopen("holstein.in","r");
    FILE *fout = fopen("holstein.out", "w");
    int i, j; 
    fscanf(fin, "%d", &v); 
    for( i = 0 ; i < v ; i++ ) {
        fscanf(fin, "%d", &vita[i]); 
        choose[i] = 0x7FFFFFFF; 
    }
    fscanf(fin, "%d", &g); 
    for( i = 0 ; i < g ; i++ ) {
        for( j = 0 ; j < v ; j++ ) {
            fscanf(fin, "%d", &feed[i][j]); 
        }
    }
    solve(0); 
    fprintf(fout, "%d ", count); 
    for( i = 0 ; i < count - 1 ; i++ ) {
        fprintf(fout, "%d ", final_result[i]); 
    }
    fprintf(fout, "%d\n", final_result[i]); 
    return 0;
}
