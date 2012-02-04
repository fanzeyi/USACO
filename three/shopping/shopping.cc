/*
USER: fanzeyi1
LANG: C++
TASK: shopping
*/
/*
 * =====================================================================================
 * 
 *       Filename:  shopping.cc
 *        Created:  02/03/2012 06:21:23 PM
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdlib>
#include <cstdio>
#include <cstring>

inline int min(int a, int b) {
    return a < b ? a : b; 
}

class Discount {
public:
    int num; 
    int price; 
    int need[10]; 
    void input(FILE *fin); 
}; 

class Plan {
public:
    int need; 
    int price; 
    void set_data(int need, int price); 
}; 

int s; 
Discount discounts[101]; 
int b; 
Plan plans[6]; 
int idnow = 1; 
int idhash[1000]; // optimize id to <= 5
int f[6][6][6][6][6]; 

void Discount::input(FILE *fin) {
    fscanf(fin, "%d", &this->num); 
    int c, k; 
    for(int i = 0; i < this->num; i++) {
        fscanf(fin, "%d %d", &c, &k); 
        if(idhash[c] == 0) {
            idhash[c] = idnow++; 
        }
        this->need[idhash[c]] = k; 
    }
    fscanf(fin, "%d", &this->price); 
}

void Plan::set_data(int need, int price) {
    this->need = need; 
    this->price = price; 
}

int main(int argc, const char *argv[]) {
    FILE *fin = fopen("shopping.in", "r"); 
    FILE *fout = fopen("shopping.out", "w"); 
    int c, k, p; 
    fscanf(fin, "%d", &s); 
    for(int i = 0; i < s; i++) {
        discounts[i].input(fin); 
    }
    fscanf(fin, "%d", &b); 
    for(int i = 1; i <= b; i++){
        fscanf(fin, "%d %d %d", &c, &k, &p); 
        if(idhash[c] == 0) {
            idhash[c] = idnow++; 
        }
        plans[idhash[c]].set_data(k, p); 
    }
    /*  Without Discount */
    for(int i1 = 0; i1 <= plans[1].need; i1++) {
        for(int i2 = 0; i2 <= plans[2].need; i2++) {
            for(int i3 = 0; i3 <= plans[3].need; i3++) {
                for(int i4 = 0; i4 <= plans[4].need; i4++) {
                    for(int i5 = 0; i5 <= plans[5].need; i5++) {
                        f[i1][i2][i3][i4][i5] = i1 * plans[1].price + \
                                                i2 * plans[2].price + \
                                                i3 * plans[3].price + \
                                                i4 * plans[4].price + \
                                                i5 * plans[5].price; 
                        //printf("%d %d %d %d %d", i1, i2, i3, i4, i5); 
                    }
                }
            }
        }
    }
    /* Get Max Discount */
    for(int i1 = 0; i1 <= plans[1].need; i1++) {
        for(int i2 = 0; i2 <= plans[2].need; i2++) {
            for(int i3 = 0; i3 <= plans[3].need; i3++) {
                for(int i4 = 0; i4 <= plans[4].need; i4++) {
                    for(int i5 = 0; i5 <= plans[5].need; i5++) {
                        for(int i = 0; i < s; i++) {
                            if(i1 - discounts[i].need[1] >= 0 && \
                               i2 - discounts[i].need[2] >= 0 && \
                               i3 - discounts[i].need[3] >= 0 && \
                               i4 - discounts[i].need[4] >= 0 && \
                               i5 - discounts[i].need[5] >= 0) {
                                f[i1][i2][i3][i4][i5] = min(f[i1][i2][i3][i4][i5], 
                                                            f[i1 - discounts[i].need[1]] \
                                                             [i2 - discounts[i].need[2]] \
                                                             [i3 - discounts[i].need[3]] \
                                                             [i4 - discounts[i].need[4]] \
                                                             [i5 - discounts[i].need[5]] + discounts[i].price); 
                            }
                        }
                    }
                }
            }
        }
    }
    fprintf(fout, "%d\n", f[plans[1].need]\
                           [plans[2].need]\
                           [plans[3].need]\
                           [plans[4].need]\
                           [plans[5].need]); 
    return 0;
}
