#include <iostream>
using namespace std;

#define MAX 100001
int tree[MAX*4] = {0,};
int arr[MAX] = {0,};
int N,M;

int init(int node, int left, int right) {
    if (left == right) return tree[node] = arr[left];
    int mid = (left+right)/2;
    int left_node = init(node*2, left, mid);
    int right_node = init(node*2+1, mid+1, right);
    return tree[node] = left_node*right_node;
}

int update(int node, int left, int right, int idx, int val) {
    if (idx < left || idx > right) return tree[node];
    if (left == right) return tree[node] = val;
    int mid = (left+right)/2;
    int left_node = update(node*2, left, mid, idx, val);
    int right_node = update(node*2+1, mid+1, right, idx, val);
    return tree[node] = left_node*right_node;
}

int sum(int node, int left, int right, int start, int end) {
    if (end < left || start > right) return 1;
    if (start <= left && right <= end) return tree[node];
    int mid = (left+right)/2;
    int left_node = sum(node*2, left, mid, start, end);
    int right_node = sum(node*2+1, mid+1, right, start, end);
    return left_node*right_node;
}

bool solve() {
    for(int i=1;i<=N;i++) {
        int x; cin >> x;
        if (x > 0) arr[i] = 1;
        else if (x < 0) arr[i] = -1;
        else arr[i] = 0;
    }
    init(1, 1, N);
    for(int i=0;i<M;i++) {
        char op; int a, b;
        cin >> op >> a >> b;
        if (op == 'C') {
            if (b > 0) b = 1;
            else if (b < 0) b = -1;
            update(1, 1, N, a, b);
        }
        else {
            int x = sum(1, 1, N, a, b);
            if (x > 0) cout << '+';
            else if (x < 0) cout << '-';
            else cout << 0;
        }
    }
    cout << endl;
    return true;
}


int main() {
    while(cin >> N >> M) {
        solve();
    }
}