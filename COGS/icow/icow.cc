/*
USER: fanzeyi1
LANG: C++
TASK: icow
*/
/*
 * =====================================================================================
 * 
 *       Filename:  icow.cc
 *        Created:  2012年02月25日 19時51分05秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_TRACK_NUM 1003

class Player{
private:
    int track_num; 
    int track[MAX_TRACK_NUM]; 
public:
    void set_track_num(int n); 
    void get_track_info(FILE *fin); 
    int next_track(); 
}; 

void Player::set_track_num(int n) {
    this->track_num = n; 
}

void Player::get_track_info(FILE *fin) {
    for(int i = 0; i < this->track_num; i++) {
        fscanf(fin, "%d", &this->track[i]); 
    }
}

int Player::next_track() {
    int play[2] = {-1, -1}; 
    int yu; 
    int add; 
    for(int i = 0; i < this->track_num; i++) {
        if(this->track[i] > play[1]) {
            play[0] = i; 
            play[1] = this->track[i]; 
        }
    }
    add = play[1] / (this->track_num - 1); 
    yu = play[1] % (this->track_num - 1); 
    for(int i = 0; i < this->track_num; i++) {
        if(i != play[0]) {
            if(yu) {
                this->track[i] += 1; 
                yu = yu - 1; 
            }
            this->track[i] += add; 
        }
    }
    this->track[play[0]] = 0; 
    return play[0];  
}

int main() {
    FILE *fin = fopen("icow.in", "r"); 
    FILE *fout = fopen("icow.out", "w"); 
    Player icow; 
    int n, t; 
    fscanf(fin, "%d %d", &n, &t); 
    icow.set_track_num(n); 
    icow.get_track_info(fin); 
    for(int i = 0; i< t; i++) {
        fprintf(fout, "%d\n", icow.next_track() + 1); 
    }
    return 0; 
}
