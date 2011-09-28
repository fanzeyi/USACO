/*
ID: fanzeyi1
LANG: C
TASK: ariprog
*/
/*
 * =====================================================================================
 *
 *       Filename:  ariprog1.c
 *        Version:  1.0
 *        Created:  09/13/2011 02:36:44 PM
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

FILE *fin, *fout; 
int n, m; 
int max; 
int *Num; 
int *Tree; 

typedef struct result{
    int data; 
    struct result *next; 
} Result; 

Result *result[9999]; 

static int cmp(const void *p1, const void *p2) {
    return *(int*)p1 - *(int*)p2; 
}

Result *NewResult(int data){
    Result *p = (Result*)malloc(sizeof(Result)); 
    p->data = data; 
    p->next = NULL; 
    return p; 
}

void Insert(Result *start, Result *target) {
    if(start->data == target->data){
        free(target); 
        return; 
    }
    if(start->next == NULL){
        start->next = target; 
        return; 
    }else if(target->data < start->next->data){
        target->next = start->next; 
        start->next = target; 
        return; 
    }else{
        Insert(start->next, target); 
    }
}

void PrintList(Result *p, int a){
    fprintf(fout, "%d %d\n", p->data, a); 
    if(p->next != NULL){
        PrintList(p->next, a); 
    }
}

int main(void) {
    fin = fopen("ariprog.in","r");
    fout = fopen("ariprog.out", "w");
    fscanf(fin, "%d %d", &n, &m); 
    int i, j, k; 
    int last; 
    int cha; 
    int max_result = 0; 
    int flag = 0; 
    max = m * m * 2; 
    Tree = (int*)calloc(max + 1, sizeof(int)); 
    Num = (int*)calloc(max + 1, sizeof(int)); 
    for( i = 0 ; i <= m ; i++ ) {
        for( j = i ; j <= m ; j++ ) {
//            printf("%d ", i * i + j * j); 
            Num[i * m + j] = i * i + j * j; 
            Tree[i * i + j * j] = 1; 
        }
    }
    qsort(Num, max, sizeof(int), cmp); 
    while(!Num[i]){
        i++; 
    }
    i = i - 1; 
    for(  ; i < max; i++ ) {
        for( j = i + 1 ; j < max ; j++ ) {
            cha = Num[j] - Num[i]; 
            last = Num[i] + cha * ( n - 1 ); 
            if(last <= max && Tree[last]){
                flag = 0; 
                for( k = 2 ; k < n ; k++ ) {
                    if(!Tree[Num[i] + cha * k]){
                        flag = 1; 
                        break; 
                    }
                }
                if(!flag){
                    if(result[cha] == NULL){
                        Result *p = NewResult(Num[i]); 
                        result[cha] = p; 
                    }else if(Num[i] < result[cha]->data){
                        Result *p = NewResult(Num[i]); 
                        p->next = result[cha]; 
                        result[cha] = p; 
                    }else{
                        Insert(result[cha], NewResult(Num[i])); 
                    }
                    if(cha > max_result) {
                        max_result = cha; 
                    }
                }
            }
        }
    }
    flag = 0; 
    for( i = 1 ; i <= max_result ; i++ ) {
        if(result[i] != NULL){
            flag = 1; 
            PrintList(result[i], i); 
        }
    }
    if(!flag){
        fprintf(fout, "NONE\n"); 
    }
    return 0;
}
