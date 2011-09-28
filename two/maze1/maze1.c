/*
ID: fanzeyi1
LANG: C
TASK: maze1 
*/
/*
 * =====================================================================================
 *
 *       Filename:  maze1.c
 *        Version:  1.0
 *        Created:  09/28/2011 02:10:59 PM
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

int w, h; 
int f[300][300]; 
char map[300][300]; 

void floodfill(int x, int y, int distanse) {
    // 越界
    if(x == h || y == w || x == -1 || y == -1) {
        return; 
    }
    // 障碍物
    if(map[x][y] == '+' || 
       map[x][y] == '|' ||
       map[x][y] == '-') {
           return; 
    }
    if(x == 3 && y == 14) {
    }
    // 取短距离
    if(distanse < f[x][y]) {
        f[x][y] = distanse; 
    }else{
        return; 
    }
    // 四个方向扩展
    floodfill(x-1, y, distanse+1);  // 上
    floodfill(x+1, y, distanse+1);  // 下
    floodfill(x, y-1, distanse+1);  // 左
    floodfill(x, y+1, distanse+1);  // 右
}

int main(void) {
    FILE *fin = fopen("maze1.in","r");
    FILE *fout = fopen("maze1.out", "w");
    int i, j; 
    int max = 0; 
    int exit[2][2]; // [x][0] -- x;  [x][0] -- y; 
    int ep = 0; 
    fscanf(fin, "%d %d\n", &w, &h);
    w = w * 2 + 1; 
    h = h * 2 + 1; 
    for( i = 0 ; i < h ; i++ ) {
        fgets(map[i], sizeof(map[i]), fin); 
        for( j = 0 ; j < w ; j++ ) {
            f[i][j] = 0x7FFFFFFF; 
        }
        // 寻找出口 横行出口寻找
        if(ep != 2 && map[i][0] == ' ') {
            exit[ep][0] = i; 
            exit[ep][1] = 0; 
            ep = ep + 1; 
        }
        if(ep != 2 && map[i][w-1] == ' ') {
            exit[ep][0] = i; 
            exit[ep][1] = w - 1; 
            ep = ep + 1; 
        }
    }
    // 寻找第一行的出口
    if(ep != 2) {
        for( i = 0 ; i < w ; i++ ) {
            if(map[0][i] == ' ') {
                exit[ep][0] = 0; 
                exit[ep][1] = i; 
                ep = ep + 1; 
            }
            if(ep == 2) {
                break; 
            }
        }
    }
    // 寻找最后一行的出口
    if(ep != 2) {
        for( i = 0 ; i < w ; i++ ) {
            if(map[h-1][i] == ' ') {
                exit[ep][0] = h - 1; 
                exit[ep][1] = i; 
                ep = ep + 1; 
            }
            if(ep == 2) {
                break; 
            }
        }
    }
    // 开始floodfill
    // 从第一个出口开始向里floodfill
    floodfill(exit[0][0], exit[0][1], 0); 
    // 从第二个出口开始floodfill
    floodfill(exit[1][0], exit[1][1], 0); 
    for( i = 0 ; i < h ; i++ ) {
        for( j = 0 ; j < w ; j++ ) {
            if(f[i][j] == 0x7FFFFFFF){
                continue;  // 除去没有被扩展的地方,  死角之类的
            }
            if(f[i][j] > max) {
                max = f[i][j]; // 获得地图中的最远距离 
            }
        }
    }
    fprintf(fout, "%d\n", (int)((max + 1)/ 2)); 
    return 0; 
}
