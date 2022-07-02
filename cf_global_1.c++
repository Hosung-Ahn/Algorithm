#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int N,K; cin >> N >> K;
    vector<int> arr(N,0);
    for(int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    for (int x : arr) {
        ans = max(ans, x | K);
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