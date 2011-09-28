/*
ID: fanzeyi1
LANG: C
TASK: gift1 
*/
/*
 * =====================================================================================
 *
 *       Filename:  gift1.c
 *        Version:  1.0
 *        Created:  08/21/2011 04:28:10 PM
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

int number; 
char list[10][14]; 
int money[10] = {0}; 

int GetName(char *s){
    int i; 
    for( i = 0 ; i < number ; i++ ){
        if(strcmp(list[i], s) == 0){
            return i; 
        }
    }
    return -1; 
}

int main(){
    FILE *fin = fopen("gift1.in", "r"); 
    FILE *fout = fopen("gift1.out", "w"); 
    int i, j; 
    int all, num; 
    int gift; 
    int host = 0; 
    char name[14]; 
    fscanf(fin, "%d", &number); 
    for( i = 0 ; i < number ; i++ ){
        fscanf(fin, "%s", list[i]); 
    }
    for( i = 0 ; i < number ; i++ ){
        fscanf(fin, "%s", name); 
        host = GetName(name); 
        fscanf(fin, "%d %d", &all, &num); 
        if(num == 0) {
            money[host] += all; 
            continue; 
        }
        if(all == 0){
            continue; 
        }
        gift = all / num; 
        money[host] -= gift * num;
        for( j = 0 ; j < num ; j++ ){
            fscanf(fin, "%s", name); 
            money[GetName(name)] += gift; 
        }
    }
    for( i = 0 ; i < number ; i++ ){
        fprintf(fout, "%s %d\n", list[i], money[i]); 
    }
    return 0; 
}
