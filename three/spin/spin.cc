/*
USER: fanzeyi1
TASK: spin
LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

class Spin {
    private:
        int speed[5]; 
        int wheel[5][360]; 
        void Set(int n, int start, int len); 
    public:
        Spin(FILE *fin); 
        bool Check(); 
        void Move(); 
}; 

Spin::Spin(FILE *fin) {
    int num; 
    int start, len; 
    memset(wheel, 0, sizeof(wheel)); 
    for(int i = 0; i < 5; i++) {
        fscanf(fin, "%d %d", &speed[i], &num); 
        for(int j = 0; j < num; j++) {
            fscanf(fin, "%d %d", &start, &len); 
            Set(i, start, len); 
        }
    }
}

void Spin::Set(int n, int start, int len) {
    for(int i = 0;  i <= len; i++) {
        wheel[n][(start + i) % 360] = 1; 
    }
}

bool Spin::Check() {
    int flag; 
    for(int i = 0; i < 360; i++) {
        flag = 0; 
        for(int j = 0; j < 5; j++) {
            flag += wheel[j][i]; 
        }
        if(flag == 5) {
            return true; 
        }
    }
    return false; 
}

void Spin::Move() {
    int tmp[360]; 
    memset(tmp, 0, sizeof(tmp)); 
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < speed[i]; j++) {
            tmp[j] = wheel[i][j]; 
            wheel[i][j] = wheel[i][360 - speed[i] + j]; 
        }
        for(int j = 359; j >= speed[i] + speed[i]; j--) {
            wheel[i][j] = wheel[i][j-speed[i]]; 
        }
        for(int j = 0; j < speed[i]; j++) {
            wheel[i][speed[i] + j] = tmp[j]; 
        }
    }
}

int main() {
    FILE *fin = fopen("spin.in", "r");
    FILE *fout = fopen("spin.out", "w");
    Spin spin(fin); 
    for(int time = 0; time < 360; time++) {
        if(spin.Check()) {
            fprintf(fout, "%d\n", time); 
            return 0; 
        }
        spin.Move(); 
    }
    fprintf(fout, "none\n"); 
    return 0;
}
