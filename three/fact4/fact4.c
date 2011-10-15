/*
ID: fanzeyi1
LANG: C
TASK: fact4 
*/
/*
 * =====================================================================================
 *
 *       Filename:  fact4.c
 *        Version:  1.0
 *        Created:  10/15/2011 10:28:06 AM
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

int GetLast(int a) {
    if(a % 10) {
        return a % 10; 
    }
    if(a % 100) {
        return a % 100 / 10; 
    }
    if(a % 1000) {
        return a % 1000 / 100; 
    }
    if(a % 10000) {
        return a % 10000 / 1000; 
    }
    return 0; 
}

int main(void) {
    FILE *fin = fopen("fact4.in","r");
    FILE *fout = fopen("fact4.out", "w");
    int n;
    int last = 1; 
    int i; 
    fscanf(fin, "%d", &n); 
    i = 1; 
    while(i <= n) {
        last = last * i; 
        last = last % 100000; 
        while(!(last%10)) {
            last = last / 10; 
        }
        i = i + 1; 
    }
    fprintf(fout, "%d\n", last % 10); 
    return 0;
}
