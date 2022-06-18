# include <iostream>
using namespace std;
#define MAX 1000000

int Tree[MAX*4] = {0,};

void update(int node, int left, int right, int idx, int value) {
    if (right < idx || left > idx) return;
    Tree[node] += value;
    if (right == left) return;
    int mid = (left+right)/2;
    update(node*2, left, mid, idx, value);
    update(node*2+1, mid+1, right, idx, value); 
}

int find(int node, int left, int right, int end) {
    if (left > end) return 0;
    if (right <= end) return Tree[node];
    int mid = (left+right)/2;
    int a = find(node*2, left, mid, end);
    int b = find(node*2+1, mid+1, right, end);
    return a + b;
}


int binary_search(int ith) {
    int lo = 1, hi = MAX;
    while(lo < hi) {
        int mid = (lo+hi)/2;
        int mid_sum = find(1,1,MAX, mid);
        if (mid_sum < ith)
            lo = mid+1;
        else
            hi = mid;
    } 
    return lo;
}

void oper() {
    int op; cin >> op;
    switch (op) {
        case 1 : {
            int ith; cin >> ith;
            int ans = binary_search(ith);
            cout << ans << "\n";
            update(1,1,MAX,ans,-1);
            break;
        }

        case 2 : { 
            int i, val; cin >> i >> val;
            update(1,1,MAX,i,val);
            break;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        oper();
    }
}