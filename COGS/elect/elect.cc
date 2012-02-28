/*
USER: fanzeyi1
LANG: C++
TASK: elect
*/
/*
 * =====================================================================================
 * 
 *       Filename:  elect.cc
 *        Created:  2012年02月28日 20時15分22秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define COW_NUM 50003

typedef struct {
    int id; 
    int a; 
    int b; 
} Cow; 

int n, k; 
Cow cows[COW_NUM]; 

inline int cmp_a(const void *a, const void *b) {
    return (*(Cow*)b).a - (*(Cow*)a).a; 
}

inline int cmp_b(const void *a, const void *b) {
    return (*(Cow*)b).b - (*(Cow*)a).b; 
}

int main() {
    FILE *fin = fopen("elect.in", "r"); 
    FILE *fout = fopen("elect.out", "w"); 
    fscanf(fin, "%d %d", &n, &k); 
    for(int i = 0; i < n ; i++) {
        fscanf(fin, "%d %d", &cows[i].a, &cows[i].b); 
        cows[i].id = i + 1; 
    }
    qsort(cows, n, sizeof(cows[0]), cmp_a); 
    qsort(cows, k, sizeof(cows[0]), cmp_b); 
    fprintf(fout, "%d\n", cows[0].id); 
    return 0; 
}
