#include<iostream>
using namespace std;
# define ll long long

ll tree[1000000*4] = {0,};

ll sum(int node, int start, int end, int left, int right) {
    // cout << tree[node] << endl;
    if (start <= left && right <= end) return tree[node];
    if (end < left || right < start) return 0;

    int mid = (start+end)/2;
    ll left_tree = sum(node*2, start, mid, left, right);
    ll right_tree = sum(node*2+1, mid+1, end, left, right);
    return left_tree+right_tree;
}

ll update(int node, int start, int end, int idx, int value) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) {
        tree[node] = value;
        return value;
    }
    int mid = (start+end)/2;
    ll left_tree = update(node*2, start, mid, idx, value);
    ll right_tree = update(node*2+1, mid+1, end, idx, value);
    tree[node] = left_tree+right_tree;
    return tree[node];
}

int main() {
    int N,M; cin >> N >> M;
    for(int i=0;i<M;i++) {
        int op,a,b; cin >> op >> a >> b;
        if (op == 0) {
            cout << sum(1, 1, N, a,b) << endl;
        }
        else {
            update(1, 1, N, a, b);
        }
    }
}