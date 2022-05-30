# include <iostream>
using namespace std;

# define INF 1987654321

# define MAX 100000
int max_tree[MAX*4];
int min_tree[MAX*4];
int arr[MAX];

int max_init(int start, int end, int node) {
    if (start == end) return max_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return max_tree[node] =
         max(max_init(start, mid, node*2), max_init(mid+1, end, node*2+1));
}

int min_init(int start, int end, int node) {
    if (start == end) return min_tree[node] = arr[start];
    int mid = (start + end) / 2;
    return min_tree[node] = 
            min(min_init(start, mid, node*2), min_init(mid+1, end, node*2+1));
}

int find_max(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return max_tree[node];

    int mid = (start + end) / 2;
    return max(find_max(start, mid, node*2, left, right), 
                find_max(mid + 1, end, node*2+1, left, right));
}

int find_min(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return INF;
    if (left <= start && end <= right) return min_tree[node];

    int mid = (start + end) / 2;
    return min(find_min(start, mid, node*2, left, right), 
                find_min(mid+1, end, node*2+1, left, right));
}

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }   

    max_init(0,N-1,1);
    min_init(0,N-1,1);

    for (int i = 0; i < M; i++) {
        int left, right; scanf("%d %d", &left, &right);
        cout << find_min(0,N-1,1, left-1, right-1) << 
            " " << find_max(0,N-1,1,left-1,right-1) << "\n";
    }
}

