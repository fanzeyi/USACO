/*
ID: fanzeyi1
LANG: C
TASK: nocows
*/
/*
 * =====================================================================================
 *
 *       Filename:  nocows.c
 *        Version:  1.0
 *        Created:  09/23/2011 08:42:22 AM
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

int f[101][202]; 

int main(void) {
    FILE *fin = fopen("nocow.in","r");
    FILE *fout = fopen("nocow.out", "w");
    int n, k;
    fscanf(fin, "%d %d", &n, &k); 
    return 0;
}
