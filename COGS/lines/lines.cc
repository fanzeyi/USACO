/*
USER: fanzeyi1
LANG: C++
TASK: lines
*/
/*
 * =====================================================================================
 * 
 *       Filename:  lines.cc
 *        Created:  02/09/2012 08:08:52 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std; 

typedef struct {
    int x, y; 
} Point; 

int n; 
Point points[203]; 
map<double, bool> hash; 

int main() {
    FILE *fin = fopen("lines.in", "r"); 
    FILE *fout = fopen("lines.out", "w"); 
    int a, b; 
    double xie; 
    fscanf(fin, "%d", &n); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &points[i].x, &points[i].y); 
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            a = points[i].x - points[j].x;  
            b = points[i].y - points[j].y; 
            if(b != 0) {
                xie = a / b; 
            }else {
                xie = 0.0; 
            }
            printf("%lf \n", xie); 
            if(!hash[xie]) {
                hash[xie] = true; 
            }
        }
    }
    fprintf(fout, "%d\n", hash.size()); 
    return 0; 
}
