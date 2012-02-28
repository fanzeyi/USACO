/*
USER: fanzeyi1
LANG: C++
TASK: latin
*/
/*
 * =====================================================================================
 * 
 *       Filename:  latin.cc
 *        Created:  2012年02月27日 01時05分59秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

char *translate(char *src) {
    char result[50]; 
    int len = strlen(src); 
    src[len-1] = '\0'; 
    if(src[0] == 'a' || src[0] == 'e' || src[0] == 'i' || src[0] == 'o' || src[0] == 'u') {
        strcpy(result, src); 
        strcpy(&result[len-1], "cow"); 
        strcpy(src, result); 
    }else {
        strcpy(result, &src[1]); 
        result[len-2] = src[0]; 
        strcpy(&result[len-1], "ow"); 
        strcpy(src, result); 
    }
    return src; 
}

int main() {
    FILE *fin = fopen("latin.in", "r"); 
    FILE *fout = fopen("latin.out", "w"); 
    char word[50]; 
    int n; 
    fscanf(fin, "%d\n", &n); 
    for(int i = 0; i < n; i++) {
        fgets(word, 50, fin); 
        fprintf(fout, "%s\n", translate(word)); 
    }
    return 0; 
}
