#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N,K;
vector<int> p[21];

void solve() {
    int ans = 0;
    for (int i=2;i<21;i++) if (!p[i].empty()) {
        for(int j=0;j<p[i].size();j++) {
            vector<int>::iterator iter;
            iter = upper_bound(p[i].begin(), p[i].end(), p[i][j] + K);
            ans += iter - (p[i].begin() + j) - 1;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    for(int i=1;i<=N;i++) {
        string s; cin >> s;
        p[s.size()].push_back(i);
    }
    solve();
}