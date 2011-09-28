/*
ID: fanzeyi1
LANG: C
TASK: milk2 
*/
/*
 * =====================================================================================
 *
 *       Filename:  milk21.c
 *        Version:  1.0
 *        Created:  08/30/2011 10:32:27 AM
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
    FILE *fin = fopen("milk2.in","r");
    FILE *fout = fopen("milk2.out", "w");
    int n;
    int i, j; 
    int start, end; 
    int have, none; 
    int maxhave = 0; 
    int maxnone = 0;  
    int max = 0; 
    int min = 0x7FFFFFFF; 
    int time[1000000] = {0};
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d %d", &start, &end); 
        for( j = start ; j < end ; j++ ) {
            time[j] = 1; 
        }
        if(start < min) {
            min = start; 
        }
        if(end > max) {
            max = end; 
        }
    }
    have = none = 0; 
    for( i = min ; i < max ; i++ ) {
        if( i == min ){
            if(time[i]){
                have = have + 1; 
            }else{
                none = none + 1; 
            }
        }
        if(time[i] && time[i-1]){
            have = have + 1; 
        }else if(time[i] && !time[i-1]) {
            if(none > maxnone) {
                maxnone = none; 
            }
            none = 0; 
            have = 1; 
        }else if((!time[i]) && (!time[i-1])){
            none = none + 1; 
        }else if((!time[i]) && time[i-1]) {
            if(have > maxhave) {
                maxhave = have; 
            }
            none = 1; 
            have = 0; 
        }
    }
    if(none > maxnone) {
        maxnone = none; 
    }
    if(have > maxhave) {
        maxhave = have; 
    }
    fprintf(fout, "%d %d\n", maxhave, maxnone); 
    return 0;
}
