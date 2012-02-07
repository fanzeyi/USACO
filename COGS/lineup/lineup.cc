#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

inline int fmin(int a, int b) {
    return a < b ? a : b; 
}

inline int fmax(int a, int b) {
    return a > b ? a : b; 
}

class SegTree {
    private:
        struct Node {
            int l, r; 
            int max; 
            int min; 
        }; 
        Node tree[200001]; 
        void Build(int left, int right, int p); 
    public:
        SegTree(int left, int right); 
        void Insert(int what, int where, int p); 
        void Query(int left, int right, int *min, int *max, int p); 
}; 

SegTree::SegTree(int left, int right) {
    memset(tree, 0, sizeof(tree)); 
    Build(left, right, 1); 
}

void SegTree::Build(int left, int right, int p) {
    tree[p].l = left; 
    tree[p].r = right; 
    tree[p].max = 0; 
    tree[p].min = 0x7FFFFFFF; 
    if(left < right) {
        Build(left, (left + right) / 2, p * 2); 
        Build((left + right) / 2 + 1, right, p * 2 + 1); 
    }
}

void SegTree::Insert(int what, int where, int p) {
    tree[p].max = fmax(tree[p].max, what); 
    tree[p].min = fmin(tree[p].min, what); 
    if(tree[p].l != tree[p].r) {
        if(where <= (tree[p].l + tree[p].r) / 2) {
            Insert(what, where, p * 2); 
        }else{
            Insert(what, where, p * 2 + 1); 
        }
    }
}

void SegTree::Query(int left, int right, int *min, int *max, int p = 1) {
    if(left <= tree[p].l && tree[p].r <= right) {
        *min = tree[p].min; 
        *max = tree[p].max; 
        return; 
    }
    int leftmin = 0x7FFFFFFF, leftmax = 0, rightmin = 0x7FFFFFFF, rightmax = 0; 
    if(left <= (tree[p].l + tree[p].r) / 2) {
        Query(left, right, &leftmin, &leftmax, p * 2); 
    }
    if(right > (tree[p].l + tree[p].r) / 2) {
        Query(left, right, &rightmin, &rightmax, p * 2 + 1); 
    }
    *min = fmin(leftmin, rightmin); 
    *max = fmax(leftmax, rightmax); 
}

int main() {
    FILE *fin = fopen("lineup.in", "r"); 
    FILE *fout = fopen("lineup.out", "w"); 
    int n, q; 
    int cow; 
    fscanf(fin, "%d %d", &n, &q); 
    SegTree Tree(1, n); 
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%d", &cow); 
        Tree.Insert(cow, i+1, 1); 
    }
    for(int i = 0; i < q; i++) {
        int a, b; 
        fscanf(fin, "%d %d", &a, &b); 
        int min = 0x7FFFFFFF; 
        int max = 0; 
        Tree.Query(a, b, &min, &max); 
        fprintf(fout, "%d\n", max - min); 
    }
    return 0; 
}
