/*
USER: fanzeyi1
LANG: C++
TASK: racing
*/
/*
 * =====================================================================================
 * 
 *       Filename:  racing.cc
 *        Created:  2012年02月25日 17時37分20秒
 *       Compiler:  g++
 *         Author:  Zeray Rice, fanzeyi1994@gmail.com
 * 
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int max, road_num, up, flat, down; 
short int road[100002]; 

short int get_code(char a) {
    if(a == 'u') {
        return 1; 
    }else if(a == 'f') {
        return 2; 
    }else if(a == 'd') {
        return 3; 
    }
    return 0; 
}

int main() {
    FILE *fin = fopen("racing.in", "r"); 
    FILE *fout = fopen("racing.out", "w"); 
    char a;
    int now = 0; 
    int result = 0; 
    fscanf(fin, "%d %d %d %d %d\n", &max, &road_num, &up, &flat, &down); 
    for(int i = 0; i < road_num; i++) {
        fscanf(fin, "%c\n", &a); 
        road[i] = get_code(a); 
    }
    while(now <= max) {
        if(road[result] == 1 || road[result] == 3) {
            now += up + down; 
        }else if(road[result] == 2) {
            now += flat * 2; 
        }
        result = result + 1; 
    }
    fprintf(fout, "%d\n", result - 1); 
    return 0; 
}
