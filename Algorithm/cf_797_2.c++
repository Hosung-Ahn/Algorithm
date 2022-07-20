#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n,0), B(n,0);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    
    int ck = false;
    for (int i = 0; i < n; i++) {
        if (B[i] != 0) ck = true;
    }
    if (!ck) {
        cout << "YES\n";
        return;
    }

    int k = -1;

    for (int i = 0; i < n; i++) if(B[i] > 0) {
        k = A[i] - B[i];
        break;
    }
    if (k < 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (B[i] > 0 && A[i] - B[i] != k) {
            cout << "NO\n";
            return;
        }
        else if (B[i] == 0 && A[i]-B[i] > k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
