#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
int tree[MAX*4] = {0,};
int arr[MAX*4] = {0,};
int k = 1;

void init(int node, int n) {
    tree[node] = n;
    if (n==1) {
        arr[node] = k++;
        return;
    }
    int r = n/2, l = n-r;
    init(node*2, l);
    init(node*2+1, r);
}

void del_node(int node) {
    while(node) {
        tree[node]--;
        node /= 2;
    }
}

int find(int node, int k) {
    if (arr[node] > 0) {
        del_node(node);
        return arr[node];
    }
    if (tree[node*2] >= k) {
        return find(node*2,k);
    }
    else return find(node*2+1, k-tree[node*2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,K; cin >> N >> K;
    vector<int> del_arr,ans;
    int a = 0;
    for(int i=N;i>0;i--) {
        a += K-1;
        a %= i;
        del_arr.push_back(a+1);
    }
    
    init(1, N);
    for (int a : del_arr) {
        ans.push_back(find(1,a));
    }
    cout << "<";
    for (int i=0;i<ans.size()-1;i++) {
        cout << ans[i] << ", ";
    }
    cout << ans.back() << ">";
}