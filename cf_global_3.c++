#include<iostream>
#include<vector>
using namespace std;
#define ll long long

vector<pair<int,ll>> f(int n, int m) {
    vector<pair<int,ll>> ret;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ll c = 1;
        while (x % m == 0) {
            x /= m;
            c *= m;
        }
        if (ret.empty() || ret.back().first != x) ret.push_back({x,c});
        else ret.back().second += c;
    }
    return ret;
}

void solve() {
    int N,M,K; cin >> N >> M;
    vector<pair<int,ll>> a = f(N,M);
    cin >> K;
    vector<pair<int,ll>> b = f(K,M);
    cout << (a==b? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}