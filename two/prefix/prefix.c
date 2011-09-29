/*
ID: fanzeyi1
LANG: C
TASK: prefix
*/
/*
 * =====================================================================================
 *
 *       Filename:  prefix.c
 *        Version:  1.0
 *        Created:  09/29/2011 10:38:29 AM
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
#define max(a, b) (((a) > (b)) ? (a) : (b))

char word[201][11]; 
char str[200001]; 
int str_len; 
int word_len[201]; 
int used[201] = {0}; 
int word_num; 

int dp[200001]; 

void read() {
    FILE *fin = fopen("prefix.in", "r"); 
    int i = 0;
    while(1) {
        fscanf(fin, "%s", word[i]); 
        word_len[i] = strlen(word[i]); 
        if(word[i][0] == '.') {
            break; 
        }
        i = i + 1; 
    }
    word_num = i; 
    i = 0; 
    while(fscanf(fin, "%s", &str[i]) == 1) {
        i = strlen(str); 
    }
    str_len = i; 
    fclose(fin); 
}

int max_len(int p) {
    int i, j;
    int flag = 1; 
    int len = 0; 
    for( i = 0 ; i < word_num ; i++ ) {
//        if(p + word_len[i] > str_len) {
//            continue; 
//        }
        flag = 1; 
        for( j = p ; j < p + word_len[i] ; j++ ) {
            if(str[j] != word[i][j-p]) {
                flag = 0; 
                break; 
            }
        }
        if(flag && word_len[i] > len) {
            len = word_len[i]; 
        }
    }
    return len; 
}

int check(int word_p, int p) {
    if(word_len[word_p] + p > str_len) {
        return 0; 
    }
    int i; 
    for( i = p ; i < p + word_len[word_p] ; i++ ) {
        if(str[i] != word[word_p][i-p]) {
            return 0; 
        }
    }
    return 1; 
}

void solve() {
    int i, j; 
    int len; 
    for( i = str_len - 1 ; i >= 0 ; i-- ) {
        for( j = 0 ; j < word_num ; j++ ) {
            if(check(j, i)) {
                dp[i] = max(dp[i], dp[i+word_len[j]] + word_len[j]);
            }
        }
/*        len = max_len(i); 
        if(dp[i+len] != 0) {
            dp[i] = dp[i+len] + len; 
        }else{
            dp[i] = len; 
        }*/
    }
} 

void output() {
    FILE *fout = fopen("prefix.out", "w"); 
    int i; 
    for( i = 0 ; i < str_len ; i++ ) {
//        printf("%d ", dp[i]); 
    }
    fprintf(fout, "%d\n", dp[0]); 
    fclose(fout);
}

int main(void) {
    read();
    solve(); 
    output(); 

    return 0;
}
