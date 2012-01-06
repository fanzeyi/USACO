/*
 * USER: fanzeyia
 * TASK: rect1
 * LANG: c++
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std; 

class Rect {
    private:
       struct paper {
           int left, right; 
           int color; 
       }; 
       queue<paper> q; 
    public:
        Rect(int left, int right, int color); 
        void Insert(int left, int right, int color); 
        void Output(FILE *fin); 
}; 

Rect::Rect(int left, int right, int color) {
    q.push((struct paper){left, right, color}); 
}

void Rect::Insert(int left, int right, int color) {
    struct paper tmp;
    int size = q.size(); 
    for(int i = 0; i < size; i++) {
        tmp = q.front(); 
        q.pop(); 
        // 1. 不重叠
        if(right <= tmp.left || left >= tmp.right) {
            q.push(tmp); 
            continue; 
        }
        // 2. 重叠一半..
        // 下左
        if((tmp.right <= right && tmp.right >= left) && tmp.left <= left) {
            q.push((struct paper){tmp.left, left, tmp.color}); 
            continue; 
        }
        // 下右
        if(tmp.left <= right && tmp.left >= left && tmp.right >= right) {
            q.push((struct paper){right, tmp.right, tmp.color}); 
            continue; 
        }
        // 3. 包含
        // 包含
        if(left <= tmp.left && right >= tmp.right) {
            continue; 
        }
        // 被包含
        if(left >= tmp.left && right <= tmp.right) {
            q.push((struct paper){tmp.left, left, tmp.color}); 
            q.push((struct paper){right, tmp.right, tmp.color}); 
            continue; 
        }
    }
    q.push((struct paper){left, right, color}); 
}

void Rect::Output(FILE *fout) {
    int color[2501]; 
    int max = 0; 
    struct paper tmp; 
    memset(color, 0, sizeof(color)); 
    while(!q.empty()) {
        tmp = q.front(); 
        q.pop(); 
        color[tmp.color] += abs(tmp.right - tmp.left); 
        if(tmp.color > max) {
            max = tmp.color; 
        }
    }
    for(int i = 1; i <= max ; i++ ) {
        if(color[i]) {
            fprintf(fout, "%d %d\n", i, color[i]); 
        }
    }
}

int main() {
    FILE *fin = fopen("rect1_line.in", "r"); 
    FILE *fout = fopen("rect1_line.out", "w"); 
    int n; 
    int left, right, color; 
    fscanf(fin, "%d %d", &right, &n); 
    Rect rect(0, right, 1); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d %d", &left, &right, &color); 
        rect.Insert(left, right, color); 
    }
    rect.Output(fout); 
    return 0; 
}
