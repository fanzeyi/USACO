/*
ID: fanzeyi1
LANG: C
TASK: concom 
*/
/*
 * =====================================================================================
 *
 *       Filename:  concom1.c
 *        Version:  1.0
 *        Created:  09/26/2011 01:02:00 PM
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

int stock[101][101]; // i 公司拥有 j 公司的 xx 股份
int can[101][101];  // i 公司 控制 j 公司

void AddCan(int mother, int son) {
    if(can[mother][son]) {
        return; 
    }
    can[mother][son] = 1; 
    int i; 
    for( i = 0 ; i < 101 ; i++ ) {
        stock[mother][i] += stock[son][i]; 
    }
    for( i = 0 ; i < 101 ; i++ ) {
        if(can[i][mother]) {
            AddCan(i, son); 
        }
    }
    for( i = 0 ; i < 101 ; i++ ) {
        if(stock[mother][i] > 50) {
            AddCan(mother, i); 
        }
    }
    
}

void AddStock(int mother, int son, int percent) {
    int i; 
    for( i = 0 ; i < 101 ; i++ ) {
        if(can[i][mother]) {
            stock[i][son] += percent; 
        }
    }
    for( i = 0 ; i < 101 ; i++ ) {
        if(stock[i][son] > 50) {
            AddCan(i, son); 
        }
    }
}

int main(void) {
    FILE *fin = fopen("concom.in","r");
    FILE *fout = fopen("concom.out", "w");
    int n;
    int i, j; 
    int a, b, c; 
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < 101 ; i++ ) {
        for( j = 0 ; j < 101 ; j ++ ) {
            stock[i][j] = 0; 
            can[i][j] = 0; 
        }
        can[i][i] = 1; 
    }
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d %d %d", &a, &b, &c); 
        if(a == b) continue; 
        AddStock(a, b, c); 
    }
    for( i = 0 ; i < 101 ; i++ ) {
        for( j = 0 ; j < 101 ; j++ ) {
            if(i != j && can[i][j]) {
                fprintf(fout, "%d %d\n", i, j); 
            }
        }
    }
    return 0;
}
