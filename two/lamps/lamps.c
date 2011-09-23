/*
ID: fanzeyi1
LANG: C
TASK: lamps
*/
/*
 * =====================================================================================
 *
 *       Filename:  lamps.c
 *        Version:  1.0
 *        Created:  09/22/2011 09:07:42 AM
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
#define MAX_LAMP 6
#define OFF 0
#define ON 1
#define UNDEFINED -1

int n, c; 
int num; 
int final_flag = 1; 
int used[4] = {0}; 
int status[MAX_LAMP] = {1}; 
int end_status[MAX_LAMP]; 
int result[10000]; 
int count = 0; 
FILE *fout; 

void dfs(int times) {
    int i; 
    if(times == c) {
        int flag = 1; 
        for( i = 0 ; i < n ; i++ ) {
            if(end_status[i] != UNDEFINED && 
               end_status[i] != status[i]) {
                flag = 0; 
                break; 
            }
        }
        if(flag) {
            final_flag = 0; 
            for( i = 0 ; i < n ; i++ ) {
                fprintf(fout, "%d", status[i]); 
            }
            fprintf(fout, "\n"); 
        }
        return; 
    }
    // Button 1
    if(used[0] < 2) {
        for( i = 0 ; i < n ; i++ ) {
            status[i] = !status[i]; 
        }
        used[0] += 1; 
        dfs(times+1); 
        used[0] -= 1; 
        for( i = 0 ; i < n ; i++ ) {
            status[i] = !status[i]; 
        }
    }
    // Button 2
    if(used[1] < 2) { 
        for( i = 0 ; i < n ; i += 2 ) {
            status[i] = !status[i]; 
        }
        used[1] += 1; 
        dfs(times+1); 
        used[1] -= 1; 
        for( i = 0 ; i < n ; i += 2 ) {
            status[i] = !status[i]; 
        }
    }
    // Button 3
    if(used[2] < 2) {
        for( i = 1 ; i < n ; i += 2 ) {
            status[i] = !status[i]; 
        }
        used[2] += 1; 
        dfs(times+1); 
        used[2] -= 1; 
        for( i = 1 ; i < n ; i += 2 ) {
            status[i] = !status[i]; 
        }
    }
    // Button 4
    if(used[3] < 2) {
        for( i = 0 ; i < n ; i += 3 ) {
            status[i] = !status[i]; 
        }
        used[3] += 1; 
        dfs(times+1); 
        used[3] -= 1; 
        for( i = 0 ; i < n ; i += 3 ) {
            status[i] = !status[i]; 
        }
    }
}

int main(void) {
    FILE *fin = fopen("lamps.in","r");
    fout = fopen("lamps.out", "w");
    int a; 
    int i; 
    memset(end_status, UNDEFINED, sizeof(int)*MAX_LAMP); 
    fscanf(fin, "%d\n%d", &num, &c); 
    for( i = 0 ; i < n ; i++ ) {
        status[i] = ON; 
    }
    if(c > 8) {
        c = c % 8; 
    }
    if(num > 6) {
        n = 6; 
    }else{
        n = num; 
    }
    while(1) {
        fscanf(fin, "%d", &a); 
        if(a == -1) {
            break; 
        }
        end_status[a-1] = ON; 
    }
    while(1) {
        fscanf(fin, "%d", &a);
        if(a == -1) {
            break; 
        }
        end_status[a-1] = OFF; 
    }
    dfs(0); 
    if(final_flag) {
        fprintf(fout, "IMPOSSIBLE\n"); 
    }
    return 0;
}
