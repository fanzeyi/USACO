/*
ID: fanzeyi1
LANG: C
TASK: crypt1 
*/
/*
 * =====================================================================================
 *
 *       Filename:  crypt1.c
 *        Version:  1.0
 *        Created:  09/11/2011 10:32:00 AM
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

int line1[3] = {0}; 
int line2[2] = {0}; 

int number[10] = {0}; 
int count = 0; 

int CheckNumber(int num) {
    if(!number[num % 10]){
        return 0; 
    }
    if(!number[(num % 100 - num % 10) / 10]) {
        return 0; 
    }
    if(!number[(num % 1000 - num % 100) / 100]) {
        return 0; 
    }
    if(num < 1000 ){
        return 1; 
    } 
    if(!number[num / 1000]) {
        return 0; 
    }
    return 1; 
}

void dfs(int point) {
    int i; 
    switch(point) {
        case 1:
        case 2:
        case 3:{
            for( i = 1 ; i < 10 ; i++ ) {
                if(number[i]) {
                    line1[point - 1] = i; 
                    dfs(point + 1); 
                    line1[point - 1] = 0; 
                }
            }
            break; 
        }
        case 4:{
            for( i = 1 ; i < 10 ; i++ ) {
                if(number[i]) {
                    if(line1[0] * i > 10) {
                        continue; 
                    }
                    if(line1[0] * i + line1[1] * i / 10 >= 10) {
                        continue; 
                    }
                    line2[0] = i; 
                    dfs(5); 
                    line2[0] = 0; 
                }
            }
            break; 
        }
        case 5:{
            for( i = 1 ; i < 10 ; i++ ) {
                if(number[i]) {
                    if(line1[0] * i > 10){
                        continue; 
                    }
                    if(line1[0] * i + line1[1] * i / 10 >= 10) {
                        continue; 
                    }
                    line2[1] = i; 
                    dfs(6); 
                    line2[1] = 0; 
                }
            }
            break; 
        }
        case 6: { // Last Check
            int a; 
            int b; 
            int c; 
            a = line1[0] * 100 + line1[1] * 10 + line1[2]; 
            b = line2[0] * 10 + line2[1]; 
            c = a * b; 
            if(c > 9999) {
                return; 
            }
            if(a * line2[1] > 999){
                return; 
            }
            if(a * line2[0] > 999) {
                return; 
            }
            if(!CheckNumber(c)) {
                return; 
            }
            if(!CheckNumber(a * line2[1])){
                return; 
            }
            if(!CheckNumber(a * line2[0])) {
                return; 
            }
            count = count + 1; 
            return; 
        }
    }
}

int main(void)
{
    FILE *fin = fopen("crypt1.in","r");
    FILE *fout = fopen("crypt1.out", "w");
    int n, a; 
    int i; 
    fscanf(fin, "%d", &n);
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d ", &a); 
        number[a] = 1; 
    }
    dfs(1); 
    fprintf(fout, "%d\n", count); 
    return 0;
}
