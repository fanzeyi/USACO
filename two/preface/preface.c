/*
ID: fanzeyi1
LANG: C
TASK: preface
*/
/*
 * =====================================================================================
 *
 *       Filename:  preface.c
 *        Version:  1.0
 *        Created:  09/22/2011 04:49:04 AM
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

int Roman[8] = {0}; 

void RomanNum(int a) {
    switch(a / 1000) {
        case 1: Roman[6] += 1; break; 
        case 2: Roman[6] += 2; break; 
        case 3: Roman[6] += 3; break; 
    }
    switch(a / 100 - (a/1000 * 10)) {
        case 1: Roman[4] += 1; break; 
        case 2: Roman[4] += 2; break; 
        case 3: Roman[4] += 3; break; 
        case 4: Roman[4] += 1; Roman[5] += 1; break; 
        case 5: Roman[5] += 1; break; 
        case 6: Roman[4] += 1; Roman[5] += 1; break; 
        case 7: Roman[4] += 2; Roman[5] += 1; break; 
        case 8: Roman[4] += 3; Roman[5] += 1; break; 
        case 9: Roman[4] += 1; Roman[6] += 1; break; 
    }
    switch(a / 10 - (a/100 * 10)) {
        case 1: Roman[2] += 1; break; 
        case 2: Roman[2] += 2; break; 
        case 3: Roman[2] += 3; break; 
        case 4: Roman[2] += 1; Roman[3] += 1; break; 
        case 5: Roman[3] += 1; break; 
        case 6: Roman[2] += 1; Roman[3] += 1; break; 
        case 7: Roman[2] += 2; Roman[3] += 1; break; 
        case 8: Roman[2] += 3; Roman[3] += 1; break; 
        case 9: Roman[2] += 1; Roman[4] += 1; break; 
    }
    switch(a % 10) {
        case 1: Roman[0] += 1; break; 
        case 2: Roman[0] += 2; break; 
        case 3: Roman[0] += 3; break; 
        case 4: Roman[0] += 1; Roman[1] += 1; break; 
        case 5: Roman[1] += 1; break; 
        case 6: Roman[0] += 1; Roman[1] += 1; break; 
        case 7: Roman[0] += 2; Roman[1] += 1; break; 
        case 8: Roman[0] += 3; Roman[1] += 1; break; 
        case 9: Roman[0] += 1; Roman[2] += 1; break; 
    }
}

int main(void) {
    FILE *fin = fopen("preface.in","r");
    FILE *fout = fopen("preface.out", "w");
    int n; 
    int i; 
    fscanf(fin, "%d", &n); 
    for( i = 1 ; i <= n ; i++ ) {
        RomanNum(i); 
    }
    if(Roman[0]) {
        fprintf(fout, "I %d\n", Roman[0]); 
    }
    if(Roman[1]) {
        fprintf(fout, "V %d\n", Roman[1]); 
    }
    if(Roman[2]) {
        fprintf(fout, "X %d\n", Roman[2]); 
    }
    if(Roman[3]) {
        fprintf(fout, "L %d\n", Roman[3]); 
    }
    if(Roman[4]) {
        fprintf(fout, "C %d\n", Roman[4]); 
    }
    if(Roman[5]) {
        fprintf(fout, "D %d\n", Roman[5]); 
    }
    if(Roman[6]) {
        fprintf(fout, "M %d\n", Roman[6]); 
    }
    return 0;
}
