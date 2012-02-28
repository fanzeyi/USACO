/*
USER: fanzeyi1
LANG: C++
TASK: camelot
*/
/*
 * =====================================================================================
 * 
 *       Filename:  camelot.cc
 *        Created:  02/05/2012 01:53:41 AM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

typedef struct {
    int x, y; 
    bool has_king; 
} Position; 

int maxx, maxy; 
int knight_num = 0; 
Position king; 
Position knight[1000]; 

int main() {
    FILE *fin = fopen("camelot.in", "r"); 
    FILE *fout = fopen("camelot.out", "w"); 
    char a; 
    int b; 
    int target_x, target_y; 
    bool getking = false; 
    fscanf(fin, "%d %d", &maxx, &maxy); 
    while(1) {
        if(fscanf(fin, "%c", &a) == -1) {
            break; 
        }
        if(isalpha(a)) {
            fscanf(fin, "%d", &b); 
            if(!getking) {
                king.x = a - 'A' + 1; 
                king.y = b; 
                getking = true; 
            }else{
                knight[knight_num].x = a - 'A' + 1; 
                knight[knight_num++].y = b; 
            }
        }
    }
    fprintf(stdout, "Input Target Position(x y):"); 
    fscanf(stdin, "%d %d", &target_x, &target_y); 
    return 0; 
}
