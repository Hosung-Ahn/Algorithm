#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int N,K; cin >> N >> K;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int result = 0;
    for (int i = 1; i < N-1; i++) {
        if (arr[i] > arr[i-1] + arr[i+1]) result++;
    }
    cout << (K == 1 ? (N-1)/2 : result) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}