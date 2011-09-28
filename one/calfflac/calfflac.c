/*
ID: fanzeyi1
LANG: C
TASK: calfflac 
*/
/*
 * =====================================================================================
 *
 *       Filename:  calfflac.c
 *        Version:  1.0
 *        Created:  09/07/2011 02:15:01 PM
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
//#define IsLetter(ch) (((ch)>>6)==1)&&((((ch)-1)&31)<26)  
#define tohigh(ch) ((ch > 96 && ch < 123) ? ch - 32 : ch)

char a[40000]; 
int len; 
int min_left = 0; 
int max_right = 0; 

int IsLetter(char c) {
    if( c > 64 && c < 91) {
        return 1; 
    }
    if( c > 96 && c < 123) {
        return 1; 
    }
    return 0; 
}

void Check(int center) {
    int left = center - 1; 
    int right = center + 1; 
    while(left != -1 && right != len) {
        if(!IsLetter(a[left])) {
            left = left - 1; 
            continue; 
        }
        if(!IsLetter(a[right])) {
            right = right + 1; 
            continue; 
        }
        if(tohigh(a[left]) != tohigh(a[right])) {
            left = left + 1; 
            right = right - 1; 
            while(!IsLetter(a[left]) && left <= len) {
                left = left + 1; 
            }
            while(!IsLetter(a[right]) && right >= 0) {
                right = right - 1; 
            }
            break; 
        }
        left = left - 1; 
        right = right + 1; 
    }
    if(right - left == 2) {
        return; 
    }
    if(IsLetter(a[left]) && !IsLetter(a[right])) {
        left = left + 1; 
    }else if(!IsLetter(a[left]) && IsLetter(a[right])) {
        right = right - 1; 
    }
    while(!IsLetter(a[left]) && left <= len) {
        left = left + 1; 
    }
    while(!IsLetter(a[right]) && right >= 0) {
        right = right - 1; 
    }
    if(max_right - min_left < right - left) {
        min_left = left; 
        max_right = right; 
    }
}

int main(void) {
    FILE *fin = fopen("calfflac.in", "r"); 
    FILE *fout = fopen("calfflac.out", "w"); 
    int i; 
    int count; 
    i = 0; 
    while(fscanf(fin, "%c", &a[i]) != EOF) {
        i = i + 1; 
    }
    len = strlen(a); 
    for( i = 0 ; i < len ; i++ ) {
        Check(i);
    }
    count = 0; 
    for( i = min_left ; i <= max_right ; i++  )
    {
        if(IsLetter(a[i])) {
            count = count + 1; 
        }
    }
    fprintf(fout, "%d\n", count); 
    for( i = min_left ; i <= max_right ; i++  )
    {
        fprintf(fout, "%c", a[i]); 
    }
    fprintf(fout, "\n"); 
    return 0;
}
