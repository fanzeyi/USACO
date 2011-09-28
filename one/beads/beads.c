/*
ID: fanzeyi1
LANG: C
TASK: beads 
*/
/*
 * =====================================================================================
 *
 *       Filename:  beads.c
 *        Version:  1.0
 *        Created:  08/21/2011 06:25:34 PM
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
    FILE *fin = fopen("beads.in","r");
    FILE *fout = fopen("beads.out", "w");
    int i; 
    int n;
    int necklace[700]; 
    char str[350];
    int prev; 
    int ma, mb; 
    int max[2] = {-1}; 
    fscanf(fin, "%d", &n); 
    fscanf(fin, "%s", str); 
    for( i = 0 ; i < n ; i++ ){
        if(str[i] == 'r'){
            necklace[i] = 1; 
        }else if(str[i] == 'b'){
            necklace[i] = 2; 
        }else if(str[i] == 'w'){
            necklace[i] = 0; 
        }
    }
    for( i = n ; i < 2 * n ; i++ ){
        necklace[i] = necklace[i-n]; 
    }
    ma = 0; 
    mb = 0; 
    prev = -1; 
    for( i = 0 ; i < 2 * n ; i++ ) {
        if(prev == 0 || prev == necklace[i]) {
            mb = mb + 1; 
            prev = necklace[i]; 
        }else if(necklace[i] == 0){
            mb = mb + 1; 
        }else if(prev == -1){
            mb = mb + 1; 
            prev = necklace[i]; 
        }else{
            if(ma + mb > max[0]){
                max[0] = ma + mb; 
                max[1] = i - mb + 1; 
            }
            ma = mb; 
            mb = 1;
            prev = necklace[i]; 
        }
    }
    if(ma + mb > max[0]){
        max[0] = ma + mb; 
    }
    if(max[0] > n){
        fprintf(fout, "%d\n", (max[0] + 1)/ 2); 
    }else{ 
        fprintf(fout, "%d\n", max[0] + 1);
    }
    return 0;
}
