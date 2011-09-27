/*
ID: fanzeyi1
LANG: C
TASK: ttwo
*/
/*
 * =====================================================================================
 *
 *       Filename:  ttwo.c
 *        Version:  1.0
 *        Created:  09/27/2011 05:08:39 AM
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
// 地图状态
#define UNDEFINED -1
#define SPACE 0
#define STOP 1
// 方向
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
// 旋转
#define whirl(a) (a = (a + 1) % 4)
// Solution: 模拟

int main(void) {
    FILE *fin = fopen("ttwo.in","r");
    FILE *fout = fopen("ttwo.out", "w");
    int i, j; 
    int map[10][10];
    int time = 0; 
    int farmer[3] = {0}; // 0 - x 坐标; 1 - y坐标; 2 - 方向; 
    int cow[3] = {0}; 
    char a; 
    for( i = 0 ; i < 10 ; i++ ) {
        for( j = 0 ; j < 10 ; j++ ) {
            fscanf(fin, "%c", &a); 
            if(a == '\n') fscanf(fin, "%c", &a); 
            switch(a) {
                case '.': map[i][j] = SPACE; break; 
                case '*': map[i][j] = STOP; break; 
                case 'F': map[i][j] = SPACE; farmer[0] = i; farmer[1] = j; farmer[2] = NORTH; break; 
                case 'C': map[i][j] = SPACE; cow[0] = i; cow[1] = j; cow[2] = NORTH; break; 
                default : map[i][j] = UNDEFINED; 
            }
        }
    }
    while(time <= 4000) {
        // 判断相遇
        if(farmer[0] == cow[0] && farmer[1] == cow[1]) {
            fprintf(fout, "%d\n", time); 
            return 0; 
        }
        // 农夫移动
        switch(farmer[2]) {
            case NORTH: {
                if(farmer[0] != 0 && map[farmer[0]-1][farmer[1]] != STOP) {
                    farmer[0] = farmer[0] - 1; 
                }else{
                    whirl(farmer[2]); 
                }
                break; 
            } 
            case EAST: {
                if(farmer[1] != 9 && map[farmer[0]][farmer[1]+1] != STOP) {
                    farmer[1] = farmer[1] + 1; 
                }else{
                    whirl(farmer[2]); 
                }
                break; 
            }
            case SOUTH: {
                if(farmer[0] != 9 && map[farmer[0]+1][farmer[1]] != STOP) {
                    farmer[0] = farmer[0] + 1; 
                }else{
                    whirl(farmer[2]); 
                }
                break; 
            }
            case WEST: {
                if(farmer[1] != 0 && map[farmer[0]][farmer[1]-1] != STOP) {
                    farmer[1] = farmer[1] - 1; 
                }else{
                    whirl(farmer[2]); 
                }
                break; 
            }
        }
        // 奶牛动
        switch(cow[2]) {
            case NORTH: {
                if(cow[0] != 0 && map[cow[0]-1][cow[1]] != STOP) {
                    cow[0] = cow[0] - 1; 
                }else{
                    whirl(cow[2]); 
                }
                break; 
            } 
            case EAST: {
                if(cow[1] != 9 && map[cow[0]][cow[1]+1] != STOP) {
                    cow[1] = cow[1] + 1; 
                }else{
                    whirl(cow[2]); 
                }
                break; 
            }
            case SOUTH: {
                if(cow[0] != 9 && map[cow[0]+1][cow[1]] != STOP) {
                    cow[0] = cow[0] + 1; 
                }else{
                    whirl(cow[2]); 
                }
                break; 
            }
            case WEST: {
                if(cow[1] != 0 && map[cow[0]][cow[1]-1] != STOP) {
                    cow[1] = cow[1] - 1; 
                }else{
                    whirl(cow[2]); 
                }
                break; 
            }
        }
        time = time + 1; 
    }
    fprintf(fout, "0\n"); 
    return 0;
}
