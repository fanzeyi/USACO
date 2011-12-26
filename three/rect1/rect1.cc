/*
USER: fanzeyia
TASK: rect1
LANG: C++
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
           int llx, lly, urx, ury; 
           int color; 
       }; 
       queue<paper> q; 
    public:
        Rect(int llx, int lly, int urx, int ury, int color); 
        void Insert(int llx, int lly, int urx, int ury, int color); 
        void Output(FILE *fin); 
#ifdef __DEBUG__
        void Show(); 
#endif
}; 

Rect::Rect(int llx, int lly, int urx, int ury, int color) {
    q.push((struct paper){llx, lly, urx, ury, color}); 
}

void Rect::Insert(int llx, int lly, int urx, int ury, int color) {
    struct paper tmp;
    int size = q.size(); 
    //  切 x 方向
    for(int i = 0; i < size; i++) {
        tmp = q.front(); 
        q.pop(); 
        // 检查 x 方向
        if(tmp.ury >= lly || tmp.lly <= ury) {
            // 1. 不重叠
            if(urx <= tmp.llx || llx >= tmp.urx) {
                q.push(tmp); 
                continue; 
            }
            // 3. 包含
            if(llx <= tmp.llx && urx >= tmp.urx) {
                // 包含
            } else if(llx >= tmp.llx && urx <= tmp.urx) {
                // 被包含
                q.push((struct paper){tmp.llx, tmp.lly, llx, tmp.ury, tmp.color}); 
                q.push((struct paper){urx, tmp.lly, tmp.urx, tmp.ury, tmp.color}); 
                tmp.llx = llx; 
                tmp.urx = urx; 
            } else if((tmp.urx <= urx && tmp.urx >= llx) && tmp.llx <= llx) {
                // 2. 重叠一半..
                // 下左
                q.push((struct paper){tmp.llx, tmp.lly, llx, tmp.ury, tmp.color}); 
                tmp.llx = llx; 
            } else if(tmp.llx <= urx && tmp.llx >= llx && tmp.urx >= urx) {
                // 下右
                q.push((struct paper){urx, tmp.lly, tmp.urx, tmp.ury, tmp.color}); 
                tmp.urx = urx; 
            }
        }
        // 检查 y 方向
        if(urx >= tmp.llx || tmp.urx >= llx) {
            // 1. 不重叠
            if(ury <= tmp.lly || lly >= tmp.ury) {
                q.push(tmp); 
                continue; 
            }
            // 3. 包含
            // 包含
            if(lly <= tmp.lly && ury >= tmp.ury) {
                // 特殊情况..
                if(urx <= tmp.llx || llx >= tmp.urx) {
                    q.push(tmp); 
                }
                continue; 
            }
            // 被包含
            if(lly >= tmp.lly && ury <= tmp.ury) {
                q.push((struct paper){tmp.llx, ury, tmp.urx, tmp.ury, tmp.color}); 
                q.push((struct paper){tmp.llx, tmp.lly, tmp.urx, lly, tmp.color}); 
                continue; 
            }
            // 2. 重叠一半..
            // 偏上
            if((tmp.lly <= ury && tmp.lly >= lly) && tmp.ury >= ury) {
                q.push((struct paper){tmp.llx, ury, tmp.urx, tmp.ury, tmp.color}); 
                continue; 
            }
            // 偏下
            if(tmp.ury <= ury && tmp.ury >= lly && tmp.lly <= lly) {
                q.push((struct paper){tmp.llx, tmp.lly, tmp.urx, lly, tmp.color}); 
                continue; 
            }
        }
        q.push(tmp); 
    }
    q.push((struct paper){llx, lly, urx, ury, color}); 
}

void Rect::Output(FILE *fout) {
    int color[2501]; 
    int max = 0; 
    struct paper tmp; 
    memset(color, 0, sizeof(color)); 
    while(!q.empty()) {
        tmp = q.front(); 
        q.pop(); 
        color[tmp.color] += abs(tmp.urx - tmp.llx) * abs(tmp.ury - tmp.lly); 
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

#ifdef __DEBUG__
void Rect::Show() {
    int size = q.size(); 
    int color[2501]; 
    int max = 0; 
    struct paper tmp; 
    memset(color, 0, sizeof(color)); 
    for(int i = 0; i < size; i++) {
        tmp = q.front(); 
        q.pop(); 
        color[tmp.color] += abs(tmp.urx - tmp.llx) * abs(tmp.ury - tmp.lly); 
        printf("%d %d %d %d %d\n", tmp.llx, tmp.lly, tmp.urx, tmp.ury, tmp.color); 
        if(tmp.color > max) {
            max = tmp.color; 
        }
        q.push(tmp); 
    }
    printf("--------[Count]--------\n"); 
    for(int i = 1; i <= max ; i++ ) {
        if(color[i]) {
            printf("%d %d\n", i, color[i]); 
        }
    }
    printf("-----------------------\n"); 
}
#endif

int main() {
    FILE *fin = fopen("rect1.in", "r"); 
    FILE *fout = fopen("rect1.out", "w"); 
    int n; 
    int llx, lly, urx, ury, color; 
    fscanf(fin, "%d %d %d", &urx, &ury, &n); 
    Rect rect(0, 0, urx, ury, 1); 
#ifdef __DEBUG__
    rect.Show();
#endif
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d %d %d %d %d", &llx, &lly, &urx, &ury, &color); 
        rect.Insert(llx, lly, urx, ury, color); 
#ifdef __DEBUG__
        rect.Show(); 
#endif
    }
    rect.Output(fout); 
    return 0; 
}
