/*
USER: fanzeyi1
LANG: C++
TASK: stats
*/
/*
 * =====================================================================================
 * 
 *       Filename:  stats.cc
 *        Created:  02/07/2012 01:54:41 AM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b; 
}

int main() {
    FILE *fin = fopen("stats.in", "r"); 
    FILE *fout = fopen("stats.out", "w"); 
    int n;
    int number[503]; 
    int add = 0; 
    double avg; 
    fscanf(fin, "%d", &n); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &number[i]); 
        add = add + number[i]; 
    }
    avg = add / (float)n; 
    fprintf(fout, "%.6lf\n", avg); 
    qsort(number, n, sizeof(number[0]), cmp); 
    if(n%2) {
        fprintf(fout, "%.6f", (float)number[n/2]); 
    }else{
        double middleadd = (number[n/2] + number[n/2-1]) / 2.0; 
        fprintf(fout, "%6lf", middleadd); 
    }
    return 0; 
}
