#include <iostream>
using namespace std;
#define MAX 1000000
#define ll long long
ll Tree[MAX*4] = {0,};
ll Lazy[MAX*4] = {0,};
ll arr[MAX+1];

ll init(int node, int left, int right) {
    if (left == right) return Tree[node] = arr[left];
    int mid = (left+right)/2;
    ll leftVal = init(node*2, left, mid);
    ll rightVal = init(node*2+1, mid+1, right);
    return Tree[node] = leftVal + rightVal;
}

void updateLazy(int node, int left, int right) {
    if (Lazy[node] != 0) {
        Tree[node] += Lazy[node]*(right-left+1);
        if (left != right) {
            Lazy[node*2] += Lazy[node];
            Lazy[node*2+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}

void update(int node, int left, int right, int start, int end, ll val) {
    updateLazy(node, left, right);
    if (start > right || end < left) return;    

    if (left >= start && right <= end) {
        Tree[node] += (right-left+1)*val;
        if (left != right) {
            Lazy[node*2] += val;
            Lazy[node*2+1] += val;
        }
        return;
    }

    int mid = (left+right)/2;
    update(node*2, left, mid, start, end, val);
    update(node*2+1, mid+1, right, start, end, val);
    Tree[node] = Tree[node*2] + Tree[node*2+1];
}

ll find_val(int node, int left, int right, int start, int end) {
    updateLazy(node,left, right);
    if (start > right || end < left) return 0;

    if (left >= start && right <= end) return Tree[node];

    int mid = (left+right)/2;
    ll leftVal = find_val(node*2, left, mid, start, end);
    ll rightVal = find_val(node*2+1, mid+1, right, start, end);
    return leftVal + rightVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M,K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1,1,N);
    for (int i = 0; i < M+K; i++) {
        int op; cin >> op;
        switch (op) {
            case 1 : {
                int s,e;
                ll v;
                cin >> s >> e >> v;
                update(1,1,N,s,e,v);
                break;
            }

            case 2 : {
                int s,e; cin >> s >> e;
                cout << find_val(1,1,N,s,e) << "\n";
                break;
            }
        }
    }
}