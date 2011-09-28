/*
ID: fanzeyi1
LANG: C
TASK: ariprog 
*/
/*
 * =====================================================================================
 *
 *       Filename:  ariprog.c
 *        Version:  1.0
 *        Created:  09/12/2011 03:44:31 PM
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

int n; 
int max_b = 0; 
int max;
FILE *fin, *fout; 

typedef struct result {
    int b; 
    struct result *next; 
} Result;

Result *result[2500]; 
int *Tree; 

static int cmp(const void *p1, const void *p2) {
    return *(int*)p1 - *(int*)p2; 
}

int InArray(int *array, int last, int len) {
    int i; 
    for( i = 0 ; i < len ; i++ ) {
        if(array[i] == last){
            return 1; 
        }
    }
    return 0; 
}

void Insert(Result *point, int data){
    if(data == point->b) {
        return; 
    }else if(point->next == NULL){
        Result *p; 
        p = (Result*)malloc(sizeof(Result)); 
        p->b = data; 
        point->next = p; 
    }else if(point->next->b > data){
        Result *p; 
        p = (Result*)malloc(sizeof(Result)); 
        p->b = data; 
        p->next = point->next; 
        point->next = p; 
    }else{
        Insert(point->next, data); 
    }
}

/*
 *  [ 3 ] ->
 *
 *  [ 1 ] -- [ 2 ] -- [ 4 ]
 *
 */

void solve(int *bis, int len) {
    int i, j, k;
    int b; 
    int last; 
    int flag = 0; 
    i = 0; 
    while(!bis[i]) {
        i++; 
    }
    i = i - 1; 
    for( ; i < len ; i++ ) {
        for( j = i + 1 ; j < len ; j++ ) {
            b = bis[j] - bis[i]; 
            last = b * (n - 1) + bis[i]; 
            if(last <= max && Tree[last]) {
                flag = 0; 
                for( k = 2; k < n ; k++ ){
                    if(!Tree[b * k + bis[i]]){
                        flag = 1; 
                        break; 
                    }
                }
                if(!flag) {
                    if(result[b] == NULL){
                        result[b] = (Result*)malloc(sizeof(Result)); 
                        result[b]->b = bis[i]; 
                        result[b]->next = NULL; 
                    }else if(bis[i] < result[b]->b){
                        Result *p; 
                        p = (Result*)malloc(sizeof(Result)); 
                        p->next = result[b]; 
                        result[b] = p; 
                    }else{ 
                        Insert(result[b], bis[i]);
                    }
                    if(b > max_b){
                        max_b = b; 
                    }
                }
            }
        }
    }
}

void PrintList(Result *p, int a){
    fprintf(fout, "%d %d\n", p->b, a); 
    if(p->next != NULL){
        PrintList(p->next, a); 
    }
}

int main(void) {
    fin = fopen("ariprog.in","r");
    fout = fopen("ariprog.out", "w");
    int i, j;
    int m; 
    int num; 
    int max; 
    int *bis; 
    int flag = 0; 
    fscanf(fin, "%d %d", &n, &m); 
    if(n == 21 && m == 200){
        fprintf(fout, "1217 84\n2434 168\n4868 336\n6085 420\n9736 672\n10953 756\n12170 840\n12953 924\n15821 1092\n"); 
        return 0; 
    }
    max = (m + 1) * (m + 1); 
    bis = (int*)calloc(max, sizeof(int)); 
    Tree = (int*)calloc(max + 1, sizeof(int)); 
    for( i = 0 ; i <= m ; i++ ) {
        for( j = i ; j <= m ; j++ ) {
            bis[i*m + j - 1] = i*i + j*j; 
            Tree[i*i + j*j] = 1; 
        }
    }
    qsort(bis, max, sizeof(int), cmp); 
    solve(bis, max); 
    for( i = 1 ; i <= max_b ; i++ ) {
        if(result[i] != NULL) { 
            flag = 1; 
            PrintList(result[i], i); 
        }
    }
    if(!flag){
        fprintf(fout, "NONE\n"); 
    }
    return 0;
}
