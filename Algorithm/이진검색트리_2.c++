#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define MAX 987654321
map<int, ll> tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N; cin >> N;
    ll cnt = 0;
    tree[0] = -1;
    tree[MAX] = -1;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        map<int,ll>::iterator lower, upper = tree.upper_bound(x);
        lower = upper--;
        tree[x] = max(lower->second, upper->second) + 1;
        cnt += tree[x];
        cout << cnt << "\n";
    }
}