/*
ID: fanzeyi1
LANG: C
TASK: dualpal 
*/
/*
 * =====================================================================================
 *
 *       Filename:  dualpal.c
 *        Version:  1.0
 *        Created:  08/30/2011 02:55:22 PM
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

char *Convert(int num, int base){
    char *result = (char*)malloc(sizeof(char) * 20); 
    int s = num; 
    int i = 0; 
    while(s != 0) {
        result[i] = s % base; 
        s = s / base; 
        i++; 
    }
    result[i] = -1; 
    for( i = 0 ; result[i] != -1 ; i++ ) {
        switch(result[i]){
            case 0: result[i] = '0'; break; 
            case 1: result[i] = '1'; break; 
            case 2: result[i] = '2'; break; 
            case 3: result[i] = '3'; break; 
            case 4: result[i] = '4'; break; 
            case 5: result[i] = '5'; break; 
            case 6: result[i] = '6'; break; 
            case 7: result[i] = '7'; break; 
            case 8: result[i] = '8'; break; 
            case 9: result[i] = '9'; break; 
            case 10: result[i] = 'A'; break; 
            case 11: result[i] = 'B'; break; 
            case 12: result[i] = 'C'; break; 
            case 13: result[i] = 'D'; break; 
            case 14: result[i] = 'E'; break; 
            case 15: result[i] = 'F'; break; 
            case 16: result[i] = 'G'; break; 
            case 17: result[i] = 'H'; break; 
            case 18: result[i] = 'I'; break; 
            case 19: result[i] = 'J'; break; 
            case 20: result[i] = 'K'; break; 
            default: result[i] = '\0'; break; 
        }
    }
    result[i] = '\0'; 
    return result; 
}

int is_PalinNum(char *num){
    int len = strlen(num); 
    int i; 
    for( i = 0 ; i < len / 2 ; i++ ){
        if(num[i] != num[len-1-i]){
            return 0; 
        }
    }
    return 1; 
}

int is_MutiPalin(int num) {
    int i = 2;
    int count = 0; 
    for( i = 2 ; i <= 10 ; i++ ) {
        if(is_PalinNum(Convert(num, i))) {
            if(count == 1) {
                return 1; 
            }else{
                count = 1; 
            }
        }
    }
    return 0; 
}

int main(void)
{
    FILE *fin = fopen("dualpal.in","r");
    FILE *fout = fopen("dualpal.out", "w");
    int n;
    int s; 
    int i; 
    int count = 0; 
    fscanf(fin, "%d %d", &n, &s); 
    for( i = s+1 ; count < n; i++ ) {
        if(is_MutiPalin(i)) {
            fprintf(fout, "%d\n", i); 
            count = count + 1; 
        }
    }
    return 0;
}
