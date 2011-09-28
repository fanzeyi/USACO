/*
ID: fanzeyi1
LANG: C
TASK: milk2 
*/
/*
 * =====================================================================================
 *
 *       Filename:  milk2.c
 *        Version:  1.0
 *        Created:  08/29/2011 11:29:56 AM
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
#define MAX 1000000

int main(){
    FILE *fin = fopen("milk2.in", "r"); 
    FILE *fout = fopen("milk2.out", "w"); 
    int n; 
    int i; 
    int j; 
    int time[MAX]; 
    int start, end; 
    int maxtime = 0; 
    int mintime = 0x7FFFFFFF; 
    int have, none; 
    int mh, mn; 
    fscanf(fin, "%d", &n); 
    for(i = 0 ; i < n ; i++ ){
        fscanf(fin, "%d %d", &start, &end); 
        for( j = start; j < end ; j++ ){
            time[j] = 1; 
        }
        if(end > maxtime){
            maxtime = end; 
        }
        if(start < mintime){
            mintime = start; 
        }
    }
    have = 0; 
    none = 0; 
    mh = 0; 
    mn = 0; 
    printf("%d", maxtime); 
    for(i = mintime ; i < maxtime ; i++ ) {
        if(time[i] == 0){
            none = none + 1; 
        }else{
            have = have + 1; 
        }
        if( i != mintime && time[i] != time[i-1]){
            if(time[i]){
                mn = none; 
                none = 0; 
                have = 1; 
            }else{
                mh = have;
                have = 0; 
                none = 1; 
            }
        }
    }
    if(none > mn){
        mn = none; 
    }
    if(have > mh){
        mh = have; 
    }
    fprintf(fout, "%d %d\n", mh, mn); 
    return 0; 
}
