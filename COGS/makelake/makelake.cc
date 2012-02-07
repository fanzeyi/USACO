/*
USER: fanzeyi1
LANG: C++
TASK: makelake
*/
/*
 * =====================================================================================
 * 
 *       Filename:  makelake.cc
 *        Created:  02/07/2012 02:23:40 AM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[102][102]; 
int r, c, e, n; 

void hit_land(int x, int y, int depth) {
    int max = 0; 
    for(int i = x; i < x + 3 && i <= r; i++) {
        for(int j = y; j < y + 3 && j <= c; j++) {
            if(map[i][j] > max) {
                max = map[i][j]; 
            }
        }
    }
    max = max - depth; 
    for(int i = x; i < x + 3 && i <= r; i++) {
        for(int j = y; j < y + 3 && j <= c; j++) {
            if(map[i][j] > max) {
                map[i][j] = max; 
            }
        }
    }
}

int main() {
    FILE *fin = fopen("makelake.in", "r"); 
    FILE *fout = fopen("makelake.out", "w"); 
    int x, y, depth; 
    long int count = 0; 
    long long int result = 0; 
    fscanf(fin, "%d %d %d %d", &r, &c, &e, &n); 
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            fscanf(fin, "%d", &map[i][j]); 
        }
    }
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d %d", &x, &y, &depth); 
        hit_land(x, y, depth); 
    }
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(e - map[i][j] > 0) {
                count = count + (e - map[i][j]); 
            }
        }
    }
    result = count * 72 * 72; 
    fprintf(fout, "%lld", result); 
    return 0; 
}
