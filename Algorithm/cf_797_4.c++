#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve() {
    int n,m; string s;
    cin >> n >> m >> s;
    vector<int> arr;
    arr.push_back(0);

    int sum = 0;
    for (char c : s) {
        if (c == 'W') sum++;
        arr.push_back(sum);
    }
    int ans = 987654321;
    for (int i = 0; i <= n-m; i++) {
        ans = min(ans, arr[i+m] - arr[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}