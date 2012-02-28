/*
USER: fanzeyi1
LANG: C++
TASK: read
*/
/*
 * =====================================================================================
 * 
 *       Filename:  read.cc
 *        Created:  2012年02月26日 21時47分57秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_COW 1003

int n; 
int book; 

class Cow {
private:
    int s, t, r; 
public:
    void _init_cow(FILE *fin); 
    int get_time(); 
}; 

void Cow::_init_cow(FILE *fin) {
    fscanf(fin, "%d %d %d\n", &this->s, &this->t, &this->r); 
}

int Cow::get_time() {
    int now_min = 0; 
    int now_page = 0; 
    int timer = 0;
    while(now_page < book) {
        if(timer == this->t) {
            now_min = now_min + this->r; 
            timer = 0; 
        }
        now_page = now_page + this->s; 
        timer = timer + 1; 
        now_min = now_min + 1; 
    }
    return now_min; 
}

Cow cow[MAX_COW]; 

int main() {
    FILE *fin = fopen("read.in", "r"); 
    FILE *fout = fopen("read.out", "w");
    fscanf(fin, "%d %d\n", &book, &n); 
    for(int i = 0; i < n; i++) {
        cow[i]._init_cow(fin); 
        fprintf(fout, "%d\n", cow[i].get_time()); 
    }
    return 0; 
}
