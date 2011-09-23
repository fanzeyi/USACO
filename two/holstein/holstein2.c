/*
ID: fanzeyi1
LANG: C
TASK: holstein 
*/
/*
 * =====================================================================================
 *
 *       Filename:  holstein2.c
 *        Version:  1.0
 *        Created:  09/22/2011 01:27:29 AM
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
int used[16] = {0}; 
int result[16]; 
int now[26];
int min = 0x7FFFFFFF; 

void input() {
    FILE *fin = fopen("holstein.in", "r"); 
    int i, j; 
    fscanf(fin, "%d", &v); 
    for( i = 0 ; i < v ; i++ ) {
        fscanf(fin, "%d", &vita[i]); 
    }
    fscanf(fin, "%d", &g); 
    for( i = 0 ; i < g ; i++ ) {
        for( j = 0 ; j < v ; j++ ) {
            fscanf(fin, "%d", &feed[i][j]); 
        }
    }
    fclose(fin); 
}

void solve(int times, int count) {
    int i; 
    if(times == g) {
        for( i = 0 ; i < v ; i++ ) {
            if(now[i] < vita[i]) return; 
        }
        if(count < min) {
            min = count; 
            for( i = 0 ; i < g ; i++ ) {
                result[i] = used[i]; 
            }
        }
        return; 
    }
    for( i = 0 ; i < v ; i++ ) {
        now[i] += feed[times][i]; 
    }
    used[times] = 1; 
    solve(times+1, count+1); 
    for( i = 0 ; i < v ; i++ ) {
        now[i] -= feed[times][i]; 
    }
    used[times] = 0; 
    solve(times+1, count); 
}

void output() {
    int i; 
    int flag = 0; 
    FILE *fout = fopen("holstein.out", "w"); 
    fprintf(fout, "%d ", min); 
    for( i = 0 ; i < g ; i++ ) {
        if(result[i]) {
            if(flag) {
                fprintf(fout, " "); 
            }
            fprintf(fout, "%d", i+1); 
            flag = 1; 
        }
    }
    fprintf(fout, "\n"); 
}

int main(void) {
    input(); 
    solve(0, 0); 
    output(); 
    return 0;
}
