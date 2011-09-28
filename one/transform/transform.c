/*
ID: fanzeyi1
LANG: C
TASK: transform 
*/
/*
 * =====================================================================================
 *
 *       Filename:  transform.c
 *        Version:  1.0
 *        Created:  08/30/2011 11:12:45 AM
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

int main(void)
{
    FILE *fin = fopen("transform.in","r");
    FILE *fout = fopen("transform.out", "w");
    int n;
    int i, j; 
    int it, jt; 
    int got = 1; 
    char **start; 
    char **target; 
    char **temp; 
    fscanf(fin, "%d", &n); 
    start = (char**)malloc(sizeof(char*) * n); 
    target = (char**)malloc(sizeof(char*) * n); 
    temp = (char**)malloc(sizeof(char*) * n); 
    for( i = 0 ; i < n ; i++ ) {
        start[i] = (char*)malloc(sizeof(char) * n); 
        target[i] = (char*)malloc(sizeof(char) * n); 
        temp[i] = (char*)malloc(sizeof(char) * n); 
        fscanf(fin, "%s", start[i]); 
    }
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%s", target[i]); 
    }
    /* Plan 1 */
    got = 1; 
    for( i = 0, it = 0 ; i < n ; i++, it++ ) {
        for( j = n-1, jt = 0 ; j >= 0 ; j--, jt++ ) {
            if(start[j][i] != target[it][jt] ){
                got = 0; 
                i = n; 
                break; 
            }
        }
    }
    if(got){
        fprintf(fout, "1\n"); 
        return 0; 
    }
    /* Plan 2 */
    got = 1; 
    for( i = n-1,  it = 0 ; i >= 0 ; i--, it++ ){
        for( j = n-1, jt = 0; j >= 0 ; j--, jt++ ){
            if(start[i][j] != target[it][jt]){
                got = 0; 
                i = -1; 
                break; 
            }
        }
    } 
    if (got) {
        fprintf(fout, "2\n"); 
        return 0; 
    }
    /* Plan 3 */
    got = 1; 
    for( i = n-1, it = 0 ; i >= 0 ; i--, it++ ) {
        for( j = 0, jt = 0 ; j < n ; j++, jt++ ) {
            if(start[j][i] != target[it][jt]) {
                got = 0; 
                i = -1; 
                break; 
            }
        }
    }
    if(got) {
        fprintf(fout, "3\n"); 
        return 0; 
    }
    /* Plan 4 */
    got = 1; 
    for( i = 0, it = 0 ; i < n ; i++, it++ ) {
        for( j = n-1, jt = 0 ; j >= 0 ; j--, jt++ ) {
            temp[it][jt] = start[i][j]; 
            if(start[i][j] != target[it][jt]) {
                got = 0; 
            }
        }
    }
    if(got) { 
        fprintf(fout, "4\n"); 
        return 0; 
    }
    /* Plan 5-1 */
    got = 1; 
    for( i = 0, it = 0 ; i < n ; i++, it++ ) {
        for( j = n-1, jt = 0 ; j >= 0 ; j--, jt++ ) {
            if(temp[j][i] != target[it][jt] ){
                got = 0; 
                i = n; 
                break; 
            }
        }
    }
    if(got){
        fprintf(fout, "5\n"); 
        return 0; 
    } 
    /* Plan 5-2 */
    got = 1; 
    for( i = n-1, it = 0 ; i >= 0 ; i--, it++ ){
        for( j = n-1, jt = 0; j >= 0 ; j--, jt++ ){
            if(temp[i][j] != target[it][jt]){
                got = 0; 
                i = -1; 
                break; 
            }
        }
    }
    if(got) {
        fprintf(fout, "5\n"); 
        return 0; 
    } 
    /* Plan 5-3 */
    got = 1; 
    for( i = n-1, it = 0 ; i >= 0 ; i--, it++ ) {
        for( j = 0, jt = 0 ; j < n ; j++, jt++ ) {
            if(temp[j][i] != target[it][jt]) {
                got = 0; 
                i = -1; 
                break; 
            }
        }
    }
    if(got) { 
        fprintf(fout, "5\n"); 
        return 0; 
    }
    /* Plan 6 */
    got = 1; 
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            if(start[i][j] != target[i][j]) {
                got = 0; 
                i = n; 
                break; 
            }
        }
    }
    if(got) {
        fprintf(fout, "6\n"); 
        return 0; 
    } 
    fprintf(fout, "7\n"); 
    return 0;
}
