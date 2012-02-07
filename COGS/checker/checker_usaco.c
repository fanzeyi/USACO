/*
ID: fanzeyi1
LANG: C
TASK: checker 
*/
/*
 * =====================================================================================
 *
 *       Filename:  checker.c
 *        Version:  1.0
 *        Created:  09/16/2011 03:45:12 PM
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
#include <math.h>

FILE *fout; 
int n; 
int count = 0; 
int result[100]; 
int binary[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384}; 

void PrintTable() {
    int i; 
    for( i = 0 ; i < n ; i++ ) {
        if(i != 0){
            fprintf(fout, " "); 
        }
        switch(result[i]){
            case 1: fprintf(fout, "1"); break; 
            case 2: fprintf(fout, "2"); break; 
            case 4: fprintf(fout, "3"); break; 
            case 8: fprintf(fout, "4"); break; 
            case 16: fprintf(fout, "5"); break; 
            case 32: fprintf(fout, "6"); break; 
            case 64: fprintf(fout, "7"); break; 
            case 128: fprintf(fout, "8"); break; 
            case 256: fprintf(fout, "9"); break; 
            case 512: fprintf(fout, "10"); break; 
            case 1024: fprintf(fout, "11"); break; 
            case 2048: fprintf(fout, "12"); break; 
            case 4096: fprintf(fout, "13"); break; 
            case 8192: fprintf(fout, "14"); break; 
        }
    }
    fprintf(fout, "\n"); 
}

void SearchSix(int row, int ld, int rd, int times){
    if(row == binary[n]-1){
        if(count < 3) {
            PrintTable(); 
        }
        count++; 
        return; 
    }
    int p; 
    int pos = binary[n]-1 & ~ (row | ld | rd); 
    while(pos != 0){
        p = pos & -pos; 
        pos = pos - p; 
        result[times] = p; 
        SearchSix(row+p, (ld+p) << 1, (rd+p) >> 1, times+1); 
        result[times] = -1; 
    }
}

int main(void) {
    FILE *fin = fopen("checker.in","r");
    fout = fopen("checker.out", "w");
    fscanf(fin, "%d", &n);
    // 4096 2048 1024 512 256 128 64 32 16 8 4 2 1
    SearchSix(0, 0, 0, 0); 
    printf("  a"); 
    fprintf(fout, "%d\n", count);
    return 0;
}
