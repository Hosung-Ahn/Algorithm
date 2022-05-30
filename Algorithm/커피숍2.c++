# include <iostream>
using namespace std;

# define MAX 100010
# define ll long long
ll arr[MAX] = {0,};
ll tree[MAX*4] = {0,};

ll init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2 +1);
}

ll sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
    if (end < idx || idx < start) return;
    tree[node] += diff;
    if (start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
} 

int main() {
    int N,M; cin >> N >> M;
    for (int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);

    init(1, N, 1);

    for (int i = 0; i < M; i++) {
        int x,y,a,b; scanf("%d %d %d %d", &x,&y,&a,&b);
        if (x > y) { 
            int tmp = x;
            x = y;
            y = tmp;
        }
        cout << sum(1,N,1,x,y) << "\n";
        update(1,N,1,a,b-arr[a]);
        arr[a] = b;
    }
}