/*
ID: fanzeyi1
LANG: C
TASK: contact 
*/
/*
 * =====================================================================================
 *
 *       Filename:  contact.c
 *        Version:  1.0
 *        Created:  10/12/2011 06:26:28 PM
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

int list[9000]; 
int back[9000]; 
int a, b, n; 
int max = 0; 

char *binn(int num) {
    char *result = (char*)malloc(sizeof(char) * 22);
    char *rev = (char*)malloc(sizeof(char)*22);
    int s = num;
    int i = 0;
    int len;
    int base = 2; 
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

void add(int num, int n) {
    num = num & ((1 << n) - 1); 
    num = num | (1 << n); 
    list[num] += 1; 
    back[num] += 1; 
    if(num > max) {
        max = num; 
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a; 
}

int main(void) {
    FILE *fin = fopen("contact.in","r");
    FILE *fout = fopen("contact.out", "w");
    int bin; 
    int bit; 
    int flag; 
    int i, j; 
    fscanf(fin, "%d %d %d", &a, &b, &n); 
    i = 0; 
    while(fscanf(fin, "%1d", &bin) != -1) {
        bit = bit << 1; 
        if(bin) {
            bit = bit | 1; 
        }
        if(i < b) {
            i++; 
        }
        for( j = a ; j <= i ; j++ ) {
            add(bit, j); 
        }
    }
    qsort(back, max+1, sizeof(back[0]), cmp); 
    bit = 0; // 第几个max 
    i = 0; // 打印了多少个数了
    bin = 0; // 上一个的max是多少
    while(i < n) {
        if(back[bit] == 0) {
            break; 
        }
        if(back[bit] == bin) {
            bin = back[bit]; 
            bit = bit + 1; 
            continue; 
        }
        flag = 0; 
        fprintf(fout, "%d\n", back[bit]); 
        for( j = 0 ; j <= max ; j++ ) {
            if(list[j] == back[bit]) {
                if(flag == 6) {
                    fprintf(fout, "\n"); 
                    flag = 0;  
                }else if(flag) {
                    fprintf(fout, " "); 
                }
                fprintf(fout, "%s", &binn(j)[1]); 
                flag = flag + 1; 
            }
        }
        bin = back[bit]; 
        i = i + 1; 
        bit += 1; 
        fprintf(fout, "\n"); 
    }
    return 0;
}
