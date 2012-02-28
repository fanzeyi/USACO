/*
USER: fanzeyi1
LANG: C++
TASK: diningb
*/
/*
 * =====================================================================================
 * 
 *       Filename:  diningb.cc
 *        Created:  2012年02月28日 19時20分11秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_COW 30003

int n; 
int cow[MAX_COW]; 
int dp[MAX_COW]; 

int nosplit() {
    int count = 0; 
    for(int i = 0; i < n; i++) {
        if(cow[i] == 1) {
            count = count + 1; 
        }
    }
    return count; 
}

int main() {
    FILE *fin = fopen("diningb.in", "r"); 
    FILE *fout = fopen("diningb.out", "w"); 
    int min; 
    fscanf(fin, "%d", &n); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &cow[i]); 
    }
    dp[0] = nosplit(); 
    min = dp[0]; 
    for(int i = 0; i < n; i++) {
        if(cow[i] == 1) {
            dp[i+1] = dp[i] - 1; 
        }else if(cow[i] == 2) {
            dp[i+1] = dp[i] + 1; 
        }
        if(dp[i+1] < min) {
            min = dp[i+1]; 
        }
    }
    fprintf(fout, "%d\n", min); 
    return 0; 
}
