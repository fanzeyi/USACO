/*
ID: fanzeyi1
LANG: C++
TASK: msquare 
*/
/*
 * =====================================================================================
 *
 *       Filename:  msquare.cc
 *        Version:  1.0
 *        Created:  12/26/2011 03:06:47 PM
 *       Revision:  none
 *       Compiler:  g++
 *         Author:  Zeray Fan, fanzeyi1994[at]gmail.com
 * 
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

#define SOLU_UNDEFINE 0
#define SOLU_A        1
#define SOLU_B        2
#define SOLU_C        3

using namespace std;

struct msquare {
    short p[7]; 
    short solu[25]; 
}; 

int count = 0; 
bool used[40320]; 
int flags = false; 
int target; 

queue<msquare> q; 

void printResult(struct msquare result) {
    FILE *fout = fopen("msquare.out", "w"); 
    int i = 0; 
    fprintf(fout, "%d\n", count); 
    while(result.solu[i] != SOLU_UNDEFINE) {
        switch(result.solu[i]) {
            case SOLU_A: fprintf(fout, "A"); break; 
            case SOLU_B: fprintf(fout, "B"); break; 
            case SOLU_C: fprintf(fout, "C"); break; 
        }
        i = i + 1; 
    }
    fprintf(fout, "\n"); 
}

int getLast(short *arr) {
    int result = 36; 
    for( int i = 0 ; i < 7 ; i++ ) {
        result = result - arr[i]; 
    }
    return result; 
}

int jc(int a) {
    if(a > 1) {
        return a * jc(a - 1); 
    }else{
        return 1; 
    }
}

int getContor(short *arr) {
    int mark[9] = {0, 0, 1, 2, 3, 4, 5, 6, 7}; 
    int result = 0; 
    for( int i = 0 ; i < 7 ; i++ ) {
        result = result + jc(7 - i) * mark[arr[i]]; 
        mark[arr[i]] = -1; 
        for( int j = arr[i] + 1; j < 9 ; j++ ) {
            mark[j] = mark[j] - 1; 
        }
    }
    result += mark[getLast(arr)]; 
    return result; 
}

void bfs() {
    int size = q.size(); 
    int contor; 
    int last; 
    struct msquare tmp; 
    struct msquare a; 
    for(int i = 0; i < size; i++) {
        tmp = q.front(); 
        q.pop(); 
        contor = getContor(tmp.p); 
        last = getLast(tmp.p); 
        memcpy(a.solu, tmp.solu, sizeof(tmp.solu)); 
        if(used[contor]) {
            continue; 
        }
        if(contor == target) {
            flags = true; 
            printResult(tmp); 
            return; 
        }
        // ---* A *---
        a.p[0] = last; 
        a.p[1] = tmp.p[6];
        a.p[2] = tmp.p[5];
        a.p[3] = tmp.p[4];
        a.p[4] = tmp.p[3];
        a.p[5] = tmp.p[2];
        a.p[6] = tmp.p[1];
        a.solu[count] = SOLU_A;
        q.push(a); 
        // ---* B *---
        a.p[0] = tmp.p[3]; 
        a.p[1] = tmp.p[0];
        a.p[2] = tmp.p[1];
        a.p[3] = tmp.p[2];
        a.p[4] = tmp.p[5];
        a.p[5] = tmp.p[6];
        a.p[6] = last;
        a.solu[count] = SOLU_B; 
        q.push(a); 
        // ---* C *---
        a.p[0] = tmp.p[0]; 
        a.p[1] = tmp.p[6];
        a.p[2] = tmp.p[1];
        a.p[3] = tmp.p[3];
        a.p[4] = tmp.p[4];
        a.p[5] = tmp.p[2];
        a.p[6] = tmp.p[5];
        a.solu[count] = SOLU_C;
        q.push(a); 
        used[contor] = true; 
    }
    count = count + 1; 
    bfs(); 
}

int main(void) {
    FILE *fin = fopen("msquare.in","r");
    short a[8]; 
    for( int i = 0 ; i < 8 ; i++ ) {
        fscanf(fin, "%hi", &a[i]); 
    }
    target = getContor(a); 
    q.push((msquare){{1, 2, 3, 4, 5, 6, 7}}); 
    bfs(); 
    return 0;
}
