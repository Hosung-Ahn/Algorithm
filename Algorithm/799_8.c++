#include<iostream>
#include<vector>
#include<map>
using namespace std;

int fun(const vector<int> &arr, int l, int r) {
    return 2*(r-l+1) - (arr[r]-arr[l]+1);
}

void solve() {
    int N; cin >> N;
    map<int, vector<int>> idx;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        idx[x].push_back(i);
    }

    int ans = 0, aa = 0, al = 0, ar = 0;
    for (auto it = idx.begin(); it != idx.end(); it++) {
        vector<int> now;
        now.swap(it->second);
        int l = 0;
        for (int r = 0; r < now.size(); r++) {
            int cur = fun(now, l, r);
            if (cur <= 0) {
                l = r;
                cur = 1;
            }
            if (cur > ans) {
                aa = it->first;
                al = now[l];
                ar = now[r];
                ans = cur;
            }
        }
    }
    cout << aa << " " << al+1 << " " << ar+1 << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}