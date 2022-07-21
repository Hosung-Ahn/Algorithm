#include<iostream>
#include<vector>
using namespace std;
#define ll long long


void solve() {
    int n; cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool ok = true;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) {
            ok = false;
            break;
        }
        if (sum == 0) {
            for (int j = i+1; j < n; j++) {
                if (arr[j] != 0) ok = false;
            }
            break;
        }
    }
    if (sum != 0) ok = false;

    cout << (ok ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}