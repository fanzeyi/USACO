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

int main(void) {
    FILE *fin = fopen("concom.in","r");
    FILE *fout = fopen("concom.out", "w");
    int n;
    int i; 
    int a, b, c; 
    fscanf(fin, "%d", &n); 
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d %d %d", &a, &b, &c); 
        if(company[a] == NULL) {
            company[a] = Stock(b, c); 
        }else{
            Insert(company[a], Stock(b, c)); 
        }
    }
    output(); 
    return 0;
}
