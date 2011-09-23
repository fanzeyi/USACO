/*
ID: fanzeyi1
LANG: C
TASK: runround
*/
/*
 * =====================================================================================
 *
 *       Filename:  runround.c
 *        Version:  1.0
 *        Created:  09/22/2011 08:00:53 AM
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

FILE *fout; 

int check(unsigned long num) {
    char str[90]; 
    unsigned long start; 
    int len; 
    unsigned long now; 
    int i, j; 
    int meeted[10] = {0}; 
    sprintf(str, "%ld", num); 
    start = str[0] - '0'; 
    len = strlen(str); 
    for( i = 0 ; i < len ; i++ ) {
        if(meeted[str[i] - '0'] == -1) {
            return 0; 
        }
        meeted[str[i] - '0'] = -1; 
    }
    if(meeted[0] == -1) {
        return 0; 
    }
    i = start; 
    meeted[start] = 1; 
    while(1) {
        while(i >= len) {
            i -= len; 
        }
        now = str[i] - '0'; 
        if(now == start) {
            for( j = 0 ; j < 10 ; j++ ) {
                if(meeted[j] == -1){
                    return 0; 
                }
            }
            fprintf(fout, "%ld\n", num); 
            return 1; 
        }
        if(meeted[now] == -1) {
            meeted[now] = 1; 
        }else{
            return 0; 
        }
        i += now; 
    }
}

int main(void) {
    FILE *fin = fopen("runround.in","r");
    fout = fopen("runround.out", "w");
    unsigned long start; 
    fscanf(fin, "%ld", &start); 
    start = start + 1; 
    while(!check(start)) {
        start += 1; 
    }
    return 0;
}
