/*
USER: fanzeyi1
TASK: fence
LANG: C++
*/
/*
 * =====================================================================================
 * 
 *       Filename:  fence.cc
 *        Version:  1.0
 *        Created:  2012年01月18日 18时44分09秒
 *       Compiler:  g++
 *         Author:  Zeray Rice <fanzeyi1994@gmail.com>
 * 
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

int n; 
int map[503][503]; 
int solu[10000]; 
int p = 0;

void dfs(int starter) {
    for(int i = 1; i <= 500; i++) {
        if(map[starter][i]) {
            map[starter][i] = map[starter][i] - 1; 
            map[i][starter] = map[i][starter] - 1; 
            dfs(i); 
        }
    }
    solu[p++] = starter; 
}

int main() {
    FILE *fin = fopen("fence.in", "r"); 
    FILE *fout = fopen("fence.out", "w"); 
    int a, b;
    int starter = 0;  
    fscanf(fin, "%d", &n); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &a, &b); 
        map[a][b] = map[a][b] + 1; 
        map[b][a] = map[b][a] + 1; 
        map[a][0] = map[a][0] + 1; 
        map[b][0] = map[b][0] + 1; 
    }
    for(int i = 1; i <= 500; i++) {
        if(map[i][0] % 2 == 1) {
            starter = i; 
            break; 
        }
    }
    if(starter == 0) {
        for(int i = 1; i <= 500; i++) {
            if(map[i][0]) {
                starter = i; 
                break; 
            }
        }
    }
    dfs(starter); 
    for(int i = p - 1; i >= 0; i--) {
        fprintf(fout, "%d\n", solu[i]);
    }
    return 0; 
}
