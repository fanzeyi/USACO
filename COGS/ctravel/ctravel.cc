/*
USER: fanzeyi1
LANG: C++
TASK: ctravel
*/
/*
 * =====================================================================================
 * 
 *       Filename:  ctravel.cc
 *        Created:  02/07/2012 11:12:04 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct {
    int x, y; 
} pos; 

int n, m, t; 
int f[102][102][17] = {{{0}}}; 
bool map[102][102]; 
pos start; 
pos target; 
pos offset[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 

int main() {
    FILE *fin = fopen("ctravel.in", "r"); 
    FILE *fout = fopen("ctravel.out", "w"); 
    char chr; 
    fscanf(fin, "%d %d %d", &n, &m, &t); 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            while(fscanf(fin, "%c", &chr)) {
                if(chr == '.') {
                    map[i][j] = false;
                    break; 
                }else if(chr == '*') {
                    map[i][j] = true; 
                    break; 
                }
            }
        }
    }
    fscanf(fin, "%d %d", &start.x, &start.y); 
    fscanf(fin, "%d %d", &target.x, &target.y); 
    f[start.x][start.y][0] = 1; 
    for(int k = 1; k <= t; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!map[i][j] && f[i][j][k] == 0){
                    for(int l = 0; l < 4; l++) {
                        if(i + offset[l].x <= n && i + offset[l].x > 0 && \
                           j + offset[l].y <= m && j + offset[l].y > 0) {
                            f[i][j][k] += f[i+offset[l].x][j+offset[l].y][k-1]; 
                        }
                    }
                }
            }
        }
    }
    fprintf(fout, "%d\n", f[target.x][target.y][t]); 
    return 0; 
}
