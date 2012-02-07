/*
USER: fanzeyi1
LANG: C++
TASK: checker
*/
/*
 * =====================================================================================
 * 
 *       Filename:  checker.cc
 *        Created:  02/05/2012 11:42:51 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int n; 
int count; 
int center; 
int center_count; 
int p_result = 0; 
int result[15]; 
int print_count; 
bool disallow_x[15]; 
bool disallow_tilt_x[40]; 
bool disallow_tilt_y[40]; 
bool print_finish; 
bool return_flag; 
FILE *fin; 
FILE *fout;

void print_result() {
    for(int i = 0; i < n; i++) {
        fprintf(fout, "%d ", result[i]); 
    }
    fprintf(fout, "\n"); 
}

void dfs(int y) {
    if(y > n) {
        if(!print_finish) {
            print_result(); 
            if(count == 2) {
                print_finish = true; 
            }
        }
        if(result[0] == center) {
            center_count = center_count + 1; 
        }else if(result[0] > center) {
            return_flag = true; 
        }else{
            count = count + 1; 
        }
        return; 
    }
    for(int i = 1; i <= n; i++) {
        if(!disallow_x[i] && !disallow_tilt_x[i+y] && !disallow_tilt_y[i-y+13]) {
            result[p_result++] = i; 
            disallow_x[i] = true; 
            disallow_tilt_x[i+y] = true; 
            disallow_tilt_y[i-y+13] = true; 
            dfs(y+1); 
            if(return_flag) {
                return; 
            }
            disallow_x[i] = false; 
            disallow_tilt_x[i+y] = false; 
            disallow_tilt_y[i-y+13] = false; 
            p_result = p_result - 1; 
        }
    }
}

int main() {
    fin = fopen("checker.in", "r"); 
    fout = fopen("checker.out", "w"); 
    fscanf(fin, "%d", &n); 
    center = n / 2 + 1; 
    dfs(1); 
    if(n%2) {
        fprintf(fout, "%d", count * 2 + center_count); 
    }else{
        fprintf(fout, "%d", count * 2); 
    }
    return 0; 
}
