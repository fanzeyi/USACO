/*
ID: fanzeyi1
LANG: C
TASK: ride 
*/
/*
 * =====================================================================================
 *
 *       Filename:  ride.c
 *        Version:  1.0
 *        Created:  08/21/2011 03:56:52 PM
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

int Num(const char *s){
    int i = 0; 
    int result = 1; 
    while(s[i] != '\0'){
        result *= s[i] - 64; 
        i = i + 1; 
    }
    return result; 
}

int main(){
    FILE *fin = fopen("ride.in", "r"); 
    FILE *fout = fopen("ride.out", "w"); 
    int star, group; 
    char ss[6], sg[6];
    fscanf(fin, "%s", ss); 
    fscanf(fin, "%s", sg); 
    star = Num(ss); 
    group = Num(sg); 
    if(star % 47 == group % 47) {
        fprintf(fout, "GO\n"); 
    }else{
        fprintf(fout, "STAY\n"); 
    }
    return 0; 
}
