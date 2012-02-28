/*
USER: fanzeyi1
LANG: C++
TASK: shelf
*/
/*
 * =====================================================================================
 * 
 *       Filename:  shelf.cc
 *        Created:  2012年02月25日 22時50分04秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int cmp(const void *a, const void *b) {
    return *(int*)b - *(int*)a; 
}

int main() {
    FILE *fin = fopen("shelf.in", "r"); 
    FILE *fout = fopen("shelf.out", "w"); 
    int n; 
    unsigned long long int b; 
    unsigned long long int height = 0;
    int result = 0; 
    int cows[20004] = {0}; 
    fscanf(fin, "%d %llu", &n, &b); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &cows[i]); 
    }
    qsort(cows, n, sizeof(cows[0]), cmp); 
    while(height < b) {
        height = height + cows[result++]; 
    }
    fprintf(fout, "%d", result); 
    return 0; 
}
