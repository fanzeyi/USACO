/*
USER: fanzeyi1
LANG: C++
TASK: butter
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#define FARM_NUM 802

using namespace std; 

int cow, farm, road; 
int map[FARM_NUM][FARM_NUM]; 
int cost[FARM_NUM][FARM_NUM]; 
int farms[FARM_NUM]; 

int result = 0x7FFFFFFF; 

int spfa(int begin) {
    queue<int> q; 
    bool atqueue[farm+1]; 
    int dist[farm+1];
    int ans = 0; 
    int now; 
    memset(dist, 0x7F, sizeof(dist)); 
    memset(atqueue, 0, sizeof(atqueue)); 
    dist[begin] = 0; 
    atqueue[begin] = true; 
    q.push(begin); 
    while(!q.empty()) {
        now = q.front(); 
        q.pop(); 
        atqueue[now] = false;
        for(int i = 1; i <= map[now][0]; i++) {
            if(dist[now] + cost[now][map[now][i]] < dist[map[now][i]]) {
                dist[map[now][i]] = dist[now] + cost[now][map[now][i]]; 
                if(!atqueue[map[now][i]]) {
                    q.push(map[now][i]); 
                    atqueue[map[now][i]] = true; 
                }
            }
        }
    }
    for(int i = 1; i <= farm; i++)  {
        ans = ans + dist[i] * farms[i]; 
    }
    printf("\n"); 
    return ans;  
}

int main() {
    FILE *fin = fopen("butter.in", "r"); 
    FILE *fout = fopen("butter.out", "w");
    int a, b, c; 
    memset(farms, 0, sizeof(farms)); 
    fscanf(fin, "%d %d %d", &cow, &farm, &road); 
    for(int i = 0; i < cow; i++) {
        fscanf(fin, "%d", &a); 
        farms[a] = farms[a] + 1; 
    }
    for(int i = 0; i < road; i++) {
        fscanf(fin, "%d %d %d", &a, &b, &c); 
        map[a][++map[a][0]] = b; cost[a][b] = c; 
        map[b][++map[b][0]] = a; cost[b][a] = c; 
    }
    for(int i = 1; i <= farm; i++) {
        a = spfa(i); 
        if(a < result) {
            result = a; 
        }
    }
    fprintf(fout, "%d\n", result); 
    return 0; 
}
