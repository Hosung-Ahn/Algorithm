#include <iostream>
using namespace std;
#define MAX 100000
int Tree[MAX*4] = {0,};
bool lazy[MAX*4] = {0,};

void button(int node, int start, int end) {
    Tree[node] = end-start+1 - Tree[node];
}

void updateLazy(int node, int start, int end) {
    if (!lazy[node]) return;
    lazy[node] = false;

    if(start == end) return;

    int mid = (start + end)/2;
    button(node*2, start, mid);
    lazy[node*2] = !lazy[node*2];
    button(node*2+1, mid+1,end);
    lazy[node*2+1] = !lazy[node*2+1];
}

void update(int node, int start, int end, int left, int right) {
    updateLazy(node,start,end);
    if (end < left || start > right) return;
    if (start >= left && end <= right) {
        button(node, start, end);
        lazy[node] = true;
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, left, right);
    update(node*2+1, mid+1, end, left, right);
    Tree[node] = Tree[node*2] + Tree[node*2+1];
}

int find(int node, int start, int end, int left, int right) {
    updateLazy(node, start, end);
    if (end < left || start > right) return 0;
    if (start >= left && end <= right) {
        return Tree[node];
    }
    int mid = (start+end)/2;
    int leftVal = find(node*2, start, mid, left, right);
    int rightVal = find(node*2+1, mid+1, end, left, right);
    return leftVal + rightVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int op,a,b; cin >> op >> a >> b;
        switch(op) {
            case 0 : {
                update(1,1,N,a,b);
                break;
            }
            case 1 : {
                cout << find(1,1,N,a,b) << "\n";
                break;
            }
        }
    }

    // for (int i = 1; i <= 7; i++) {
    //     cout << Tree[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= 7; i++) {
    //     cout << lazy[i] << " ";
    // }
}