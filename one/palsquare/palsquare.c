/*
ID: fanzeyi1
LANG: C
TASK: palsquare 
*/
/*
 * =====================================================================================
 *
 *       Filename:  palsquare.c
 *        Version:  1.0
 *        Created:  08/30/2011 02:13:13 PM
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
    char *rev = (char*)malloc(sizeof(char)*20); 
    int s = num; 
    int i = 0; 
    int len; 
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
    len = strlen(result); 
    for( i = 0 ; result[i] != '\0' ; i++ ) {
        rev[i] = result[len - i - 1]; 
    }
    return rev; 
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

int main(void)
{
    FILE *fin = fopen("palsquare.in","r");
    FILE *fout = fopen("palsquare.out", "w");
    char *str; 
    char *ori; 
    int n; 
    int i = 0; 
    int j;
    fscanf(fin, "%d", &n); 
//    printf("%s", Convert(90000, n)); 
    for( i = 1 ; i <= 300 ; i++ ) {
        str = Convert(i * i, n); 
        ori = Convert(i, n); 
        if(is_PalinNum(str)){
            fprintf(fout, "%s %s\n", ori, str); 
        }
    }
    return 0;
}
