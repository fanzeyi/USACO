/*
ID: fanzeyi1
LANG: C
TASK:  pprime
*/
/*
 * =====================================================================================
 *
 *       Filename:  pprime.c
 *        Version:  1.0
 *        Created:  09/13/2011 07:10:49 PM
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

int LenNumber(int a){
    if(a > 10000000) {
        return 8; 
    }
    if(a > 1000000) {
        return 7; 
    }
    if(a > 100000) {
        return 6;
    }
    if(a > 10000) {
        return 5; 
    }
    if(a > 1000) {
        return 4; 
    }
    if(a > 100) {
        return 3; 
    }
    if(a > 10) {
        return 2; 
    }
    return 1; 
}

int Prime(int a){
    int i; 
    int max = sqrt(a);
    for( i = 2 ; i <= max ; i++ ) {
        if(a % i == 0){
            return 0; 
        }
    }
    return 1; 
}

void solve(int start, int end, int lena, int lenb, \
           FILE *fout) {
    /* 1 */
    if(lena == 1) {
        if(start == 5) {
            fprintf(fout, "5\n"); 
        }
        if(start <= 7 && end >= 7 ) {
            fprintf(fout, "7\n"); 
        }
    }
    if(lenb == 1){
        return; 
    }
    /* 2 */
    if(lena <= 2) {
        if(start <= 11 && end >= 11) {
            fprintf(fout, "11\n"); 
        }
    }
    if(lenb == 2) {
        return; 
    }
    int i, j;
    int a; 
    /* 3 */
    if(lena <= 3) {
        for( i = 1 ; i <= 9 ; i = i + 2 ) {
            if(i == 5){
                continue; 
            }
            for( j = 0 ; j <= 9 ; j++ ) {
                a = i * 100 + j * 10 + i; 
                if(a >= start && a <= end && Prime(a)){
                    fprintf(fout, "%d\n", a); 
                }
                if(a >= end){
                    return; 
                }
            }
        }
    }
    if(lenb == 3) {
        return; 
    }
    /* 4 
     * 没有长度为 4 的回文质数 略去
     */
    if(lenb == 4) {
        return; 
    }
    /* 5 */
    int k; 
    for( i = 1 ; i <= 9 ; i = i + 2 ) {
        if(i == 5){
            continue; 
        }
        for( j = 0 ; j <= 9 ; j++ ) {
            for( k = 0 ; k <= 9 ; k++ ) {
                a = i * 10000 + j * 1000 + k * 100 + j * 10 + i; 
                if(a >= start && a <= end && Prime(a)){
                    fprintf(fout, "%d\n", a); 
                }
                if(a >= end){
                    return; 
                }
            }
        }
    }
    if(lenb == 5){
        return; 
    }
    /* 6 */
    for( i = 1 ; i <= 9 ; i = i + 2 ) {
        if(i == 5){
            continue; 
        }
        for( j = 0 ; j <= 9 ; j++ ) {
            for( k = 0 ; k <= 9 ; k++ ) {
                a = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i; 
                if(a >= start && a <= end && Prime(a)){
                    fprintf(fout, "%d\n", a); 
                }
                if(a >= end){
                    return; 
                }
            }
        }
    }
    if(lenb == 6){
        return; 
    }
    /* 7 */
    int l; 
    for( i = 1 ; i <= 9 ; i++ ) {
        if(i == 5){
            continue; 
        }
        for( j = 0 ; j <= 9 ; j++ ) {
            for( k = 0 ; k <= 9 ; k++ ) {
                for( l = 0 ; l <= 9 ; l++ ) {
                    a = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
                    if(a >= start && a <= end && Prime(a)){
                        fprintf(fout, "%d\n", a); 
                    }
                    if(a >= end){
                        return; 
                    }
                }
            }
        }
    }
}

int main(void)
{
    FILE *fin = fopen("pprime.in","r");
    FILE *fout = fopen("pprime.out", "w");
    int a, b;
    int lena, lenb; 
    fscanf(fin, "%d %d", &a, &b); 
    lena = LenNumber(a); 
    lenb = LenNumber(b); 
    solve(a, b, lena, lenb, fout); 
    return 0;
}
