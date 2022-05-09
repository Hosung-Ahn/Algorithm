#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
# define MAX 100000+1
# define INF 1987654321
             

int arr[MAX] = {0,};
vector<int> tree;

int init(int node, int start, int end) {
    if (start == end) return tree[node] = start;
    int mid = (start+end)/2;

    int left = init(node*2, start, mid);
    int right = init(node*2+1, mid+1, end);

    if (arr[left] > arr[right]) return tree[node] = right;
    else return tree[node] = left;
}

int update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return start;
    
    int mid = (start+end)/2;

    int left = update(node*2, start, mid, idx);
    int right = update(node*2+1, mid+1, end, idx);


    if (arr[left] > arr[right]) return tree[node] = right;
    else return tree[node] = left;
}

int cal(int node, int start, int end, int b, int c) {
    if (c < start || end < b) return 0;
    if (start >= b && c >= end) return tree[node];

    int mid = (start + end)/2;

    int left = cal(node*2, start, mid, b, c);
    int right = cal(node*2+1, mid+1, end, b, c);
    // cout << left << " " << right << endl;

    if (arr[left] > arr[right]) return right;
    else return left;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;

    arr[0] = INF;
    for (int i = 1; i <= N; i++) 
        cin >> arr[i];

    int h = ceil(log2(N));
    tree.resize(1 << (h+1));
    init(1,1,N);

    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int a,b,c; cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(1,1,N,b);
        }
        else cout << cal(1,1,N,b,c) << "\n";
    }    
}