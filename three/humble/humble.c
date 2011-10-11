/*
ID: fanzeyi1
LANG: C
TASK: humble 
*/
/*
 * =====================================================================================
 *
 *       Filename:  humble.c
 *        Version:  1.0
 *        Created:  10/11/2011 10:03:49 AM
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

int num[101]; 
int mark[101]; 
long hum[100001]; 
int ph = 1; 

int main(void) {
    FILE *fin = fopen("humble.in","r");
    FILE *fout = fopen("humble.out", "w");
    int k, n;
    int min[2] = {0x7FFFFFFF, 0}; 
    int i; 
    fscanf(fin, "%d %d", &k, &n); 
    for( i = 0 ; i < k ; i++ ) {
        fscanf(fin, "%d", &num[i]); 
    }
    hum[0] = 1; 
    for( ; ph <= n ; ) {
        min[0] = 0x7FFFFFFF; 
        min[1] = -1; 
        for( i = 0 ; i < k ; i++ ) {
            while(num[i] * hum[mark[i]] <= hum[ph-1]) {
                mark[i] = mark[i] + 1; 
            }
            if(num[i] * hum[mark[i]] < min[0]) {
                min[0] = num[i] * hum[mark[i]]; 
                min[1] = i; 
            }
        }

        hum[ph++] = min[0]; 
        mark[min[1]] = mark[min[1]] + 1; 
    }
    fprintf(fout, "%ld\n", hum[n]);
    return 0;
}
