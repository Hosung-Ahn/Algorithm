# include <iostream>
# include <vector>
# include <cmath>
using namespace std;
# define ll long long
# define MOD 1000000007
# define MAX 1000000+1

int arr[MAX] = {0,};
vector<ll> tree;

ll Make_SegementTree(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end)/2;
    ll left = Make_SegementTree(node*2, start, mid);
    ll right = Make_SegementTree(node*2+1, mid+1, end);
    tree[node] = (left*right) % MOD;
    return tree[node];
}

ll Update(int node, int start, int end, int idx, int num) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = num;

    int mid = (start + end)/2;
    ll left = Update(node*2, start, mid, idx, num);
    ll right = Update(node*2+1, mid+1, end, idx, num);
    tree[node] = (left*right) % MOD;
    return tree[node];
}

ll Multiple(int node, int start, int end, int a, int b) {
    if (b < start || a > end) return 1;
    if (start >= a && end <= b) return tree[node];

    int mid = (start+end)/2;
    ll left = Multiple(node*2, start, mid, a, b);
    ll right = Multiple(node*2+1, mid+1, end, a, b);
    return (left * right) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N,M,K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int h = ceil(log2(N));
    int tree_size = (1 << (h+1));
    tree.resize(tree_size);

    Make_SegementTree(1,1,N);

    for (int i = 0; i < M+K; i++) {
        int a,b,c; cin >> a >> b >> c; 
        if (a == 1) {
            Update(1,1,N,b,c);
        }
        else {
            cout << Multiple(1,1,N,b,c) << "\n";
        }
    }
}