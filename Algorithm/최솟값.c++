# include <iostream> 
using namespace std;

# define MAX 100001
# define INF 1987654321

int tree[MAX*4];
int arr[MAX];

int init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start+end) / 2;
    return tree[node] = min(init(start,mid,node*2), init(mid+1,end,node*2+1));
}

int find(int start, int end, int node, int left, int right) {
    if (left  > end || right < start) return INF;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min(find(start, mid, node*2, left, right),
               find(mid+1, end, node*2+1, left, right));
} 

int main() { 
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    init(1,N,1);
    
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        cout << find(1,N,1,s,e) << "\n";
    }
}