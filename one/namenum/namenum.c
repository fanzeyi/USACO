/*
ID: fanzeyi1
LANG: C
TASK: namenum 
*/
/*
 * =====================================================================================
 *
 *       Filename:  namenum.c
 *        Version:  1.0
 *        Created:  09/03/2011 10:50:31 AM
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

char dict[256]; 

int main() {
    FILE *fin = fopen("namenum.in","r");
    FILE *fout = fopen("namenum.out", "w");
    FILE *fin2 = fopen("dict.txt", "r"); 
    char num[13]; 
    char text[13]; 
    int i; 
    int len;
    int num_len; 
    int flag = 1; 
    int DeathFlag; 
    dict['A'] = '2'; dict['B'] = '2'; dict['C'] = '2'; 
    dict['D'] = '3'; dict['E'] = '3'; dict['F'] = '3'; 
    dict['G'] = '4'; dict['H'] = '4'; dict['I'] = '4'; 
    dict['J'] = '5'; dict['K'] = '5'; dict['L'] = '5'; 
    dict['M'] = '6'; dict['N'] = '6'; dict['O'] = '6'; 
    dict['P'] = '7'; dict['R'] = '7'; dict['S'] = '7'; 
    dict['T'] = '8'; dict['U'] = '8'; dict['V'] = '8'; 
    dict['W'] = '9'; dict['X'] = '9'; dict['Y'] = '9'; 
    fscanf(fin, "%s", num); 
    num_len = strlen(num); 
    while(fscanf(fin2, "%s", text) != -1) {
        i = 0; 
        DeathFlag = 1; 
        len = strlen(text); 
        if(len != num_len) {
            continue; 
        }
        while(text[i] != '\0'){
            if(text[i] == 'Q' || text[i] == 'Z') {
                DeathFlag = 0; 
                break; 
            }
            if(dict[text[i]] != num[i]) {
                DeathFlag = 0; 
                break; 
            }
            i = i + 1; 
        }
        if(DeathFlag) {
            flag = 0;
            fprintf(fout, "%s\n", text); 
        }
    }
    if(flag) {
        fprintf(fout, "NONE\n"); 
    }
    return 0;
}
