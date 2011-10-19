/*
ID: fanzeyi1
LANG: C
TASK: spin
*/
/*
 * =====================================================================================
 *
 *       Filename:  spin.c
 *        Version:  1.0
 *        Created:  10/19/2011 08:12:11 PM
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

typedef struct {
    int speed; 
    int w; 
    int gap[5][2]; 
} Spin; 

Spin spin[5]; 
int status[5][360]; // 记录轮子状态 

void Set(int sp, int start, int len) { // sp 表示第几个轮子 下同
    int i; 
    int max = start + len; 
    status[sp][max+1] = 1; 
    for( i = start ; i <= max ; i++ ) {
        status[sp][i] = 1; 
    }
}

void Move(int sp) { // 旋转函数
    int tmp[360]; 
    int i, j; 
    j = 0; 
    for( i = 360 - spin[sp].speed ; i < 360 ; i++ ) {
        tmp[j] = status[sp][i]; 
        j++; 
    }
    for( i = 359 ; i >= spin[sp].speed ; i-- ) {
        status[sp][i] = status[sp][i - spin[sp].speed]; 
    }
    for( i = 0 ; i < spin[sp].speed ; i++ ) {
        status[sp][i] = tmp[i]; 
    }
}

int Check() {
    int flag; 
    int i, j; 
    for( i = 0 ; i < 360 ; i++ ) {
        flag = 1; 
        for( j = 0 ; j < 5 ; j++ ) {
            if(!status[j][i]) {
                flag = 0; 
                break; 
            }
        }
        if(flag) {
            return 1; 
        }
    }
    return 0; 
}

int main(void) {
    FILE *fin = fopen("spin.in","r");
    FILE *fout = fopen("spin.out", "w");
    int i, j;
    int time; 
    memset(status, 0, sizeof(status)); 
    for( i = 0 ; i < 5 ; i++ ) {
        fscanf(fin, "%d %d", &spin[i].speed, &spin[i].w); 
        for( j = 0 ; j < spin[i].w ; j++ ) {
            fscanf(fin, "%d %d", &spin[i].gap[j][0], &spin[i].gap[j][1]); 
            Set(i, spin[i].gap[j][0], spin[i].gap[j][1]); 
        }
    }
    time = 0; 
    while(time < 360) { // 旋转旋转
        if(Check()) {
            fprintf(fout, "%d\n", time); 
            return 0; 
        }
        for( i = 0 ; i < 5 ; i++ ) {
            Move(i); 
        }
        time = time + 1; 
    }
    fprintf(fout, "none\n"); 
    return 0;
}
