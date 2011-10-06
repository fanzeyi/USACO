/*
ID: fanzeyi1
LANG: C
TASK: fracdec
*/
/*
 * =====================================================================================
 *
 *       Filename:  fracdec.c
 *        Version:  1.0
 *        Created:  10/04/2011 05:59:01 PM
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

// HITS: 长除法就是传统意义上的除法. 嘛 学名而已~

int dec[100000]; 
short hash[100000]; 
int res[100000]; 
int p = 1; 
int count = 0; // 当前行字数统计~ 
FILE *fout; 

int len(int a) {
    if(a < 10) {
        return 1; 
    } 
    if(a < 100) {
        return 2; 
    }
    if(a < 1000) {
        return 3; 
    }
    if(a < 10000) {
        return 4; 
    }
    if(a < 100000) {
        return 5; 
    }
    return 0; 
}

inline void check_count() {
    count = count + 1; 
    if(count == 76) {
        fprintf(fout, "\n"); 
        count = 0; 
    }
}

void solve(int a, int b) {
    // 长除法
    int i; 
    int mod; 
    if(a % b == 0) {
        fprintf(fout, "%d.", dec[0]); 
        count = len(dec[0]) + 1; 
        for( i = 1 ; i < p ; i++ ) {
            fprintf(fout, "%hi", dec[i]); 
            check_count(); 
        } 
        fprintf(fout, "%d\n", a/b); 
        return; 
    }else{
        dec[p] = a / b; 
        res[p] = a % b; 
        mod = a % b;
        if(hash[mod]) {
            // 进入循环处理阶段
            fprintf(fout, "%d.", dec[0]); 
            count = len(dec[0]) + 1; 
            i = 0; 
            while(1) {
                if(res[i] == mod) {
                    fprintf(fout, "(%d", dec[i+1]); 
                    check_count(); 
                    check_count(); 
                    break; 
                }
                fprintf(fout, "%d", dec[i+1]); 
                check_count(); 
                i = i + 1; 
            }
            i = i + 1; 
            while(1) {
                if(res[i] == mod) {
                    fprintf(fout, ")\n"); 
                    check_count(); 
                    break; 
                }
                fprintf(fout, "%d", dec[i+1]);
                check_count(); 
                i = i + 1; 
            }
            return; 
        }
        hash[mod] = 1; 
        solve(res[p++]*10, b); 
    }
}

int main(void) {
    FILE *fin = fopen("fracdec.in","r");
    int n, d;
    fout = fopen("fracdec.out", "w");
    fscanf(fin, "%d %d", &n, &d); 
    dec[0] = n / d; 
    res[0] = n % d; 
    hash[res[0]] = 1; 
    solve(res[0] * 10, d); 
    return 0;
}
