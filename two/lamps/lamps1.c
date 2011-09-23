/*
ID: fanzeyi1
LANG: C
TASK: lamps 
*/
/*
 * =====================================================================================
 *
 *       Filename:  lamps1.c
 *        Version:  1.0
 *        Created:  09/23/2011 01:36:28 AM
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
#define UNDEFINED -1
#define ON 1
#define OFF 0

int n, c; 
int flag = 1; 
int final_on[6] = {0}; 
int final_off[6] = {0}; 
int status[64] = {0}; 

void check(int now) {
    int i; 
    for( i = 0 ; i < 6 ; i++ ) {
        if(final_on[i] == UNDEFINED && final_off[i] == UNDEFINED) {
            continue; 
        }
        if(final_on[i] == ON) {
            if((now & (1 << (5-i))) == 0) {
                return; 
            }
        }
        if(final_off[i] == OFF) {
            if(((~now ^ 0xFFFFFFC0) & (1 << (5-i))) == 0) {
                return; 
            }
        }
    }
    flag = 0; 
    status[now] = 1; 
}

void dfs(int times, int now) {
    int i; 
    if(times >= c || times >= 8) {
        check(now); 
        return; 
    }
    int new = now; 
    // Button 1
    dfs(times+1, ~now ^ 0xFFFFFFC0); 
    // Button 2
    for( i = 4 ; i >= 0 ; i -= 2 ) {
        new = new ^ (1 << i); 
    }
    dfs(times+1, new); 
    new = now; 
    // Button 3
    for( i = 5 ; i >= 0 ; i -= 2 ) {
        new = new ^ (1 << i); 
    }
    dfs(times+1, new); 
    // Button 4 
    new = now; 
    for( i = 5 ; i >= 0 ; i -= 3 ) {
        new = new ^ (1 << i); 
    }
    dfs(times+1, new); 
    
}

char *convert(int a, int max) {
    char *result = (char*)calloc(max, sizeof(char));
    int i = max - 1; 
    memset(result, '0', sizeof(char)*max); 
    while(a != 0){
        result[i] = a % 2 + '0';
        a = a / 2;
        i--;
    }
    return result; 
}

void output() {
    FILE *fout = fopen("lamps.out", "w"); 
    int i; 
    int j; 
    char *p; 
    if(flag) {
        fprintf(fout, "IMPOSSIBLE\n"); 
        return; 
    }
    for( i = 0 ; i < 64 ; i++ ) {
        if(status[i]) {
            if(n <= 6) {
                fprintf(fout, "%s\n", convert(i, n)); 
            }else{
                int times = n / 6; 
                int max = n % 6; 
                p = convert(i, 6); 
                for( j = 0 ; j < times ; j++ ) {
                    fprintf(fout, "%s", p); 
                }
                for( j = 0 ; j < max ; j++ ) {
                    fprintf(fout, "%c", p[j]); 
                }
                fprintf(fout, "\n"); 
            }
        }
    }
}

int main(void) {
    FILE *fin = fopen("lamps.in","r");
    fscanf(fin, "%d\n%d", &n, &c);
    int i; 
    int a; 
    for( i = 0 ; i < 6 ; i++ ) {
        final_on[i] = UNDEFINED; 
        final_off[i] = UNDEFINED; 
    }
    while(1) {
        fscanf(fin, "%d", &a); 
        if(a == -1) {
            break; 
        }
        a = a - 1; 
        if(a >= 6) {
            a = a % 6; 
        }
        final_on[a] = ON; 
    }
    while(1) {
        fscanf(fin, "%d", &a);
        if(a == -1) {
            break; 
        }
        a = a - 1; 
        if(a > 6) {
            a = a % 6; 
        }
        final_off[a] = OFF; 
    }
    dfs(0, 63); 
    output(); 
//    printf("%s", convert(1, 2)); 
    return 0;
}
