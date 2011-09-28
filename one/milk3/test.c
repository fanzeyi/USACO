/*
ID: fanzeyi1
LANG: C
TASK: test 
*/
/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *        Version:  1.0
 *        Created:  09/13/2011 06:16:06 PM
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

int main(void)
{
    int i, j, k;
    printf("%d", 20+2000+20000-1101); 
    int num[22021] = {0}; 
    for( i = 1 ; i < 21 ; i++ ) {
        for( j = 1 ; j < 21 ; j++ ) {
            for( k = 1 ; k < 21 ; k++ ) {
                num[i+j*100+k*1000] += 1; 
            }
        }
    }
    return 0;
}
