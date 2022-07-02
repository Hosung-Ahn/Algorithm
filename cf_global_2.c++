#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) { 
            ans++;
            while(arr[i] > 0 && i < N-1) i++;
        }
    }
    cout << (ans >= 2 ? 2 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}