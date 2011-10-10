/*
ID: fanzeyi1
LANG: C
TASK: cowtour 
*/
/*
 * =====================================================================================
 *
 *       Filename:  cowtour.c
 *        Version:  1.0
 *        Created:  10/06/2011 05:31:45 PM
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
#include <float.h>
#include <math.h>

int n; 
int farm[151][2]; // farm[x][0] -- x; farm[x][1] -- y
double length[151]; 
double map[151][151]; 

double len(int a, int b) {
    return sqrt((farm[b][0] - farm[a][0]) * (farm[b][0] - farm[a][0]) + (farm[b][1] - farm[a][1]) * (farm[b][1] - farm[a][1])); 
}

//int mark(int point, int colo) {
//    if(color[point]) {
//        return 0; 
//    }
//    color[point] = colo; 
//    int i; 
//    for( i = 0 ; i < n ; i++ ) {
//        if(map[point][i]) {
//            mark(i, colo); 
//        }
//    }
//    return 1; 
//}

double maxlen(int a) {
    int i; 
    double max = 0; 
    for( i = 0 ; i < n ; i++ ) {
        if(i != a && map[a][i] != 1e100 && map[a][i] > max) {
            max = map[a][i]; 
        }
    }
    return max; 
}

double max(double a, double b) {
    return a > b ? a : b; 
}

int main(void) {
    FILE *fin = fopen("cowtour.in","r");
    FILE *fout = fopen("cowtour.out", "w");
    double min = 1e100; 
    double a; 
    int i, j, k; 
    fscanf(fin, "%d", &n);
    for( i = 0 ; i < n ; i++ ) {
        fscanf(fin, "%d %d", &farm[i][0], &farm[i][1]); 
        for( j = 0 ; j < n ; j++ ) {
            map[i][j] = 1e100; 
        }
    }
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            fscanf(fin, "%1d", &k);
            if(k) {
                map[i][j] = len(i, j); 
            }
        }
    }
    for( k = 0 ; k < n ; k++ ) {
        for( i = 0 ; i < n ; i++ ) {
            for( j = 0 ; j < n ; j++ ) {
                if(map[i][k] + map[j][k] < map[i][j]) {
                    map[i][j] = map[i][k] + map[j][k]; 
                }
            }
        }
    }
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            if(map[i][j] == 1e100) {
                printf("0 "); 
                continue; 
            }
            printf("%.2f ", map[i][j]); 
        }
        printf("\n"); 
    }
    for( i = 0 ; i < n ; i++ ) {
        length[i] = maxlen(i); 
    }
    for( i = 0 ; i < n ; i++ ) {
        a = 0; 
        for( j = 0 ; j < n ; j++ ) {
            if(map[i][j] != 1e100 && length[j] > a) {
                a = length[j]; 
            }
        }
        length[i] = a; 
    }
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            if(map[i][j] == 1e100) {
                a = max(maxlen(i) + len(i, j) + maxlen(j), max(length[i], length[j])); 
                if(a < min && a != 0) {
                    min = a; 
                }
            }
        }
    }
    fprintf(fout, "%.6f\n", min); 
    return 0;
}
