/*
ID: fanzeyi1
LANG: C
TASK: frac1 
*/
/*
 * =====================================================================================
 *
 *       Filename:  frac1.c
 *        Version:  1.0
 *        Created:  09/19/2011 08:27:35 PM
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

int n; 
FILE *fout; 

void solve(int a1, int b1, int a2, int b2) {
    if( b1 + b2 > n ) {
        return; 
    }
    solve(a1, b1, a1+a2, b1+b2); 
    fprintf(fout, "%d/%d\n", a1+a2, b1+b2); 
    solve(a1+a2, b1+b2, a2, b2); 
}

int main(void) {
    FILE *fin = fopen("frac1.in","r");
    fout = fopen("frac1.out", "w");
    fscanf(fin, "%d", &n);
    fprintf(fout, "0/1\n"); 
    solve(0, 1, 1, 1); 
    fprintf(fout, "1/1\n"); 
    return 0;
}
