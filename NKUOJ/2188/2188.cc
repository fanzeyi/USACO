/*
USER: fanzeyi1
LANG: C++
TASK: NKU 2188
*/
/*
 * =====================================================================================
 * 
 *       Filename:  2188.cc
 *        Created:  2012年03月20日 04時31分27秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define MAX_WIDTH 552
#define MAX_RESULT 1000
#ifndef DEBUG
#define fin stdin
#define fout stdout
#define MAX_RESULT 550000
#endif

int width; 
int result_p = 0; 
char result[MAX_RESULT]; 
char encode[MAX_WIDTH][MAX_WIDTH]; 
bool decode[MAX_WIDTH][MAX_WIDTH]; 

void recode_result(int x, int y, int decode_width, int decode_height) {
#ifdef DEBUG
    printf("[INFO] Recoding (%d, %d) to (%d, %d).\n", x, y, x + decode_width, y + decode_height); 
#endif
    for(int i = 0; i < decode_height; i++) {
        for(int j = 0; j < decode_width; j++) {
            if(decode[i][j]) {
                result[result_p++] = encode[x+i][y+j]; 
            }
        }
    }
}

void reverse_line(int line, int start, int decode_width) {
    for(int i = 0; i < decode_width / 2; i++) {
        decode[line][start - 1 - i] = decode[line][start + i]; 
    }
}

void reverse_column(int col, int start, int decode_width) {
    for(int i = 0; i < decode_width / 2; i++) {
        decode[start - 1 - i][col] = decode[start + i][col]; 
    }
}

void decode_odd(int decode_width) {
    for(int i = 0; i < width; i = i + decode_width) {
        // height
        for(int j = 0; j < width ; j = j + decode_width ) {
            recode_result(i, j, decode_width, decode_width); 
        }
    }
}

void decode_even(int decode_width) {
    for(int i = 0; i < width; i = i + decode_width) {
        // height
        for(int j = 0; j < width ; j = j + decode_width ) {
            recode_result(i, j, decode_width, decode_width); 
        }
    }
    // fold x 
    int mid = decode_width / 2; 
    for(int i = 0; i < decode_width; i++) {
        reverse_line(i, mid, decode_width); 
    }
    for(int i = 0; i < width; i = i + decode_width) {
        for(int j = 0; j < width; j = j + mid) {
            recode_result(i, j, mid, decode_width); 
        }
    }
    for(int i = 0; i < mid; i++) {
        reverse_column(i, mid, decode_width); 
    }
    if(mid % 2) {
        decode_odd(mid); 
    } else {
        decode_even(mid); 
    }
}

int main() {
#ifdef DEBUG
    FILE *fin = fopen("2188.in", "r"); 
    FILE *fout = fopen("2188.out", "w"); 
#endif
    char a; 
    fscanf(fin, "%d\n", &width); 
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(fin, "%c", &encode[i][j]); 
        }
        fscanf(fin, "\n"); 
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(fin, "%c", &a); 
            if(a == '1') {
                decode[i][j] = true; 
            } else {
                decode[i][j] = false; 
            }
        }
        fscanf(fin, "\n"); 
    }
    if(width % 2) {
        decode_odd(width); 
    } else {
        decode_even(width); 
    }
    for(int i = 0; i < result_p; i++) {
        fprintf(fout, "%c", result[i]); 
    }
    printf("\n"); 
    return 0; 
}
