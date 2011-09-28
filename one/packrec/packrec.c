/*
ID: fanzeyi1
LANG: C
TASK: packrec 
*/
/*
 * =====================================================================================
 *
 *       Filename:  packrec.c
 *        Version:  1.0
 *        Created:  09/11/2011 03:46:55 PM
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

int width[8]; 
int height[8]; 

int main(void)
{
    FILE *fin = fopen("packrec.in","r");
    FILE *fout = fopen("packrec.out", "w");
    int i; 
    for( i = 0 ; i < 4 ; i++ ) {
        fscanf(fin, "%d %d", &width[i], height[i]); 
        width[4+i] = width[i]; 
        height[4+i] = height[i]; 
    }

    return 0;
}
