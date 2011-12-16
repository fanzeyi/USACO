/*
USER: fanzeyi1
TASK: ratios
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

int feed[3][3]; 
int target[3]; 

int check(int i, int j, int k) {
    double a = i * feed[0][0] + j * feed[1][0] + k * feed[2][0]; 
    double b = i * feed[0][1] + j * feed[1][1] + k * feed[2][1]; 
    double c = i * feed[0][2] + j * feed[1][2] + k * feed[2][2]; 
    if(target[0] == 0 && a != 0) {
        return 0; 
    }
    if(target[1] == 0 && b != 0) {
        return 0; 
    }
    if(target[2] == 0 && c != 0) {
        return 0; 
    }
    if(target[0] != 0 && target[1] != 0 && a / target[0] != b / target[1]) {
        return 0; 
    }
    if(target[0] != 0 && target[2] != 0 && a / target[0] != c / target[2]) {
        return 0; 
    }
    if(target[1] != 0 && target[2] != 0 && b / target[1] != c / target[2]) {
        return 0; 
    }
    if(((int)a) % target[0] == 0) {
        return (int)(a / target[0]); 
    }
    return 0; 
}

int main() {
    FILE *fin = fopen("ratios.in", "r"); 
    FILE *fout = fopen("ratios.out", "w"); 
    fscanf(fin, "%d %d %d", &target[0], &target[1], &target[2]); 
    for(int i = 0; i < 3; i++) {
        fscanf(fin, "%d %d %d", &feed[i][0], &feed[i][1], &feed[i][2]); 
    }
    for(int all = 0; all < 298; all++) {
        /* 所有的饲料和 */
        for(int i = 0; i <= 99; i++) {
            /* Feed 1 */
            if(all - i < 0) {
                break; 
            }
            for (int j = 0; j <= 99; j++) {
                /* Feed 2 */
                if(all - i - j < 0) {
                    break; 
                }
                int k = all - i - j; 
                int result = check(i, j, k); 
                if(result) {
                    fprintf(fout, "%d %d %d %d\n", i, j, k, result); 
                    return 0; 
                }
            }
        }
    }
    fprintf(fout, "NONE\n"); 
    return 0; 
}


