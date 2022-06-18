#include <iostream> 
using namespace std;
#define MAX 65536
#define ll long long
int Tree[MAX*4] = {0,};
int arr[250000] = {0,};


void update(int node, int left, int right, int idx, int value) {
    if (right < idx || left > idx) return;
    Tree[node] += value;
    if (right == left) return;
    int mid = (left+right)/2;
    update(node*2, left, mid, idx, value);
    update(node*2+1, mid+1, right, idx, value); 
}

int find(int node, int left, int right, int k) {
    if (left == right) return left;
    int mid = (left+right)/2;
    int under = Tree[node*2];
    if (k <= under) return find(node*2, left, mid, k);
    else return find(node*2+1, mid+1, right, k-under);
}

void solution() {
    int N,K; cin >> N >> K;
    ll result = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        update(1,0,MAX,arr[i],1);
        if (i+1 >= K) {
            result += find(1,0,MAX,(K+1)/2);
            update(1,0,MAX,arr[i-K+1], -1);
        }
    }
    cout << result;
}

int main() {
    solution();
}

