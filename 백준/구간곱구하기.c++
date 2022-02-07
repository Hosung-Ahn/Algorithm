# include <iostream>
using namespace std;

# define MOD 1000000007
# define MAX 1000001
# define ll long long

ll tree[MAX*4];
int arr[MAX];
int N,M,K;

ll init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node*2) * init(mid+1, end, node*2+1)) % MOD;
}

void update(int start, int end, int node, int index, int dif) {
    if (index < start || index > end) return;
    tree[node] /= arr[index];
    tree[node] *= dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

ll find(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return (find(start, mid, node*2, left, right) * find(mid+1, end, node*2+1, left, right)) % MOD;
}

int main() {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    init(1,N,1);

    for (int i = 0; i < M+K; i++) {
        int op,a,b; scanf("%d %d %d", &op, &a, &b);

        switch (op) {
            case 1 : 
                update(1,N,1,a,b);
            break;
            
            case 2 :
                cout << find(1,N,1,a,b) << "\n";
            break;
        }
    }


}