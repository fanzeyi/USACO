/*
ID: fanzeyi1
LANG: C
TASK: comehome 
*/
/*
 * =====================================================================================
 *
 *       Filename:  comehome.c
 *        Version:  1.0
 *        Created:  10/04/2011 10:39:47 AM
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

int map[52][52]; 
int f[52][52]; 
int have[52]; 

int id(char c) {
    if(c <= 'Z' && c >= 'A') {
        return c - 'A'; 
    }
    if(c <= 'z' && c >= 'a') {
        return c - 'a' + 26; 
    }
    return -1; 
}

int main(void) {
    FILE *fin = fopen("comehome.in","r");
    FILE *fout = fopen("comehome.out", "w");
    int n;
    char a, b; 
    int c; 
    int i, j, k; 
    int min[2] = {0x7FFFFFFF, 0}; 
    fscanf(fin, "%d\n", &n); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%c %c %d\n", &a, &b, &c); 
        a = id(a); 
        b = id(b); 
        if(a == -1 || b == -1) {
            continue; 
        }
        have[a] = 1; 
        have[b] = 1; 
        if(map[a][b]) {
            if(c < map[a][b]) {
                map[a][b] = c;
                map[b][a] = c; 
            }
        }else{
            map[a][b] = c; 
            map[b][a] = c; 
        }
    }
    for( i = 0 ; i < 52 ; i++ ) {
        for( j = 0 ; j < 52 ; j++ ) {
            f[i][j] = map[i][j]; 
            if(f[i][j] == 0) {
                f[i][j] = 0x7FFFFFFF;
            }
        }
    }
    for( k = 0 ; k < 52 ; k++ ) {
        for( j = 0 ; j < 52 ; j++ ) {
            for( i = 0 ; i < 52 ; i++ ) {
                if(f[i][k] != 0x7FFFFFFF && f[k][j] != 0x7FFFFFFF && f[i][k] + f[j][k] < f[i][j]) {
                    f[i][j] = f[i][k] + f[j][k]; 
                }
            }
        }
    }
    for( i = 0 ; i < 25 ; i++ ) {
        if(f[25][i] && f[25][i] < min[0]) {
            min[0] = f[25][i]; 
            min[1] = i; 
        }
    }
    fprintf(fout, "%c %d\n", min[1] + 'A', min[0]); 
    return 0;
}
