/*
ID: fanzeyi1
LANG: C
TASK: agrinet 
*/
/*
 * =====================================================================================
 *
 *       Filename:  agrinet.c
 *        Version:  1.0
 *        Created:  10/09/2011 02:32:28 PM
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

int n; 
int map[101][101]; 
int dis[101]; 

int prim(int point) {
    int min[2] = {0x7FFFFFFF, -1}; 
    int i, j; 
    int result = 0; 
    for( i = 0 ; i < n ; i++ ) {
        dis[i] = map[point][i]; 
    }
    for( i = 0 ; i < n ; i++ ) {
        min[0] = 0x7FFFFFFF; 
        min[1] = 0; 
        for( j = 0 ; j < n ; j++ ) {
            if(dis[j] && dis[j] < min[0]) {
                min[0] = dis[j]; 
                min[1] = j; 
            }
        }
        if(min[0] == 0x7FFFFFFF) {
            break; 
        }
        result += min[0]; 
        dis[min[1]] = 0; 
        for( j = 0 ; j < n ; j++ ) {
            if(map[min[1]][j] < dis[j]) {
                dis[j] = map[min[1]][j]; 
            }
        }
    }
    return result; 
}

int main(void) {
    FILE *fin = fopen("agrinet.in","r");
    FILE *fout = fopen("agrinet.out", "w");
    int i, j; 
    int a; 
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            fscanf(fin, "%d", &map[i][j]); 
        }
    }
    a = prim(0); 
    fprintf(fout, "%d\n", a); 
    return 0;
}
