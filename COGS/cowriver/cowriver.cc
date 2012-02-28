/*
USER: fanzeyi1
LANG: C++
TASK: cowriver
*/
/*
 * =====================================================================================
 * 
 *       Filename:  cowriver.cc
 *        Created:  02/09/2012 07:41:47 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int n;  
int f[2503] = {0}; 
int cow[2503] = {0}; 

inline int minf(int a, int b) {
    return a < b ? a : b; 
}

int main() {
    FILE *fin = fopen("cowriver.in", "r"); 
    FILE *fout = fopen("cowriver.out", "w"); 
    int tmp; 
    fscanf(fin, "%d %d", &n, &cow[0]); 
    for(int i = 1; i <= n; i++) {
        fscanf(fin, "%d", &tmp); 
        cow[i] = cow[i-1] + tmp; 
    }
    memset(f, 0x7F, sizeof(f)); 
    f[0] = 0; 
    f[1] = cow[1] + cow[0]; 
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            f[i] = minf(f[i], cow[i-j] + cow[0] + f[j]); 
        }
    }
    fprintf(fout, "%d\n", f[n] - cow[0]); 

    return 0; 
}
