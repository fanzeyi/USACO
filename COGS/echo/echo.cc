/*
USER: fanzeyi1
LANG: C++
TASK: echo
*/
/*
 * =====================================================================================
 * 
 *       Filename:  echo.cc
 *        Created:  2012年02月27日 01時34分03秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int min(int a, int b) {
    return a < b ? a : b; 
}

int get_length(char *s1, char *s2) {
    int len = min(strlen(s1), strlen(s2)); 
    int n = 0; 
//    printf("%s %s\n", s1, s2); 
    for(int i = 0; i < len; i++) {
        if(s1[i] != s2[i]) {
            return n; 
        }
        n = n + 1; 
    }
    return n; 
}

int main() {
    FILE *fin = fopen("echo.in", "r"); 
    FILE *fout = fopen("echo.out", "w"); 
    char s1[100], s2[100]; 
    int max = 0; 
    int length = 0; 
    int len1, len2; 
    fgets(s1, 100, fin); 
    fgets(s2, 100, fin); 
    len1 = strlen(s1); 
    len2 = strlen(s2); 
    s1[len1 - 1] = '\0'; 
    s2[len2 - 1] = '\0'; 
    len1 = len1 - 1; 
    len2 = len2 - 1; 
    for(int i = 0; i < len1 - 1; i++) {
        for(int j = 0; j < len2 - 1; j++) {
            length = get_length(&s1[i], &s2[j]); 
            if(length > max) {
                max = length; 
            }
        }
    }
    fprintf(fout, "%d\n", max); 
    return 0; 
}
