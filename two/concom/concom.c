/*
ID: fanzeyi1
LANG: C
TASK: concom 
*/
/*
 * =====================================================================================
 *
 *       Filename:  concom.c
 *        Version:  1.0
 *        Created:  09/26/2011 10:01:07 AM
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

typedef struct stock{
    int company; 
    int percent; 
    struct stock *next; 
} stock; 

int n; 
FILE *out;  
stock *company[100]; 

stock *Stock(int company, int percent) {
    stock *p; 
    p = (stock*)malloc(sizeof(stock)); 
    p->company = company; 
    p->percent = percent; 
    p->next = NULL; 
    return p; 
}

void Insert(stock *mother, stock *son) {
    if(mother->next == NULL) {
        mother->next = son; 
        return; 
    }else{
        Insert(mother->next, son); 
    }
}

void output(int num) {
    stock *p = company[num]; 
    int i; 
    int max = 0; 
    int check[101] = {0}; 
    int stoc[101] = {0}; 
    while(p != NULL) {
        if(p->percent >= 50) {
            fprintf(out, "%d %d\n", num, p->company); 
            check[p->company] = 1; 
            if(p->company > max) {
                max = p->company; 
            }
        } 
        p = p->next; 
    }
    for( i = 0 ; i <= max ; i++ ) {
        if(check[i]) {
            p = company[i]; 
            while(p != NULL) {
                stoc[p->company] += p->percent; 
                p = p->next; 
            }
        }
    }
    for( i = 0 ; i < 101 ; i++ ) {
        if(stoc[i] >= 50){
            fprintf(out, "%d %d\n", num, i); 
        }
    }
    
}

int main(void) {
    FILE *fin = fopen("concom.in","r");
    int i; 
    int a, b, c; 
    out = fopen("concom.out", "w");
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d %d %d", &a, &b, &c); 
        if(company[a] == NULL) {
            company[a] = Stock(b, c); 
        }else{
            Insert(company[a], Stock(b, c)); 
        }
    }
    for( i = 0 ; i < n ; i++ ) {
        if(company[i] != NULL) {
            output(i); 
        }
    }
    return 0;
}
