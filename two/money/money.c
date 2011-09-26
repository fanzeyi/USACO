/*
ID: fanzeyi1
LANG: C
TASK: money 
*/
/*
 * =====================================================================================
 *
 *       Filename:  money.c
 *        Version:  1.0
 *        Created:  09/26/2011 02:03:23 AM
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

int main(void) {
    FILE *fin = fopen("money.in","r");
    FILE *fout = fopen("money.out", "w");
    int v, n; 
    int i; 
    int money[26]; 
    fscanf(fin, "%d %d", &v, &n);
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d", &money[i]);
    }
    return 0;
}
