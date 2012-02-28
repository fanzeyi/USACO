/*
USER: fanzeyi1
LANG: C++
TASK: bones
*/
/*
 * =====================================================================================
 * 
 *       Filename:  bones.cc
 *        Created:  2012年02月27日 01時22分15秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 100000

int s1, s2, s3; 
int count[MAX] = {0}; 

int main() {
    FILE *fin = fopen("bones.in", "r"); 
    FILE *fout = fopen("bones.out", "w");
    int max_p = 0; 
    int max[2] = {0}; 
    fscanf(fin, "%d %d %d", &s1, &s2, &s3); 
    for(int i = 1; i <= s1; i++) {
        for(int j = 1; j <= s2; j++) {
            for(int k = 1; k <= s3; k++) {
                count[i + j + k] += 1; 
                if(i + j + k > max_p) {
                    max_p = i + j + k; 
                }
            }
        }
    }
    for(int i = 3; i <= max_p; i++) {
        if(count[i] > max[0]) {
            max[0] = count[i]; 
            max[1] = i; 
        }
    }
    fprintf(fout, "%d\n", max[1]); 
    return 0; 
}
