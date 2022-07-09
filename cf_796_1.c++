#include<iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    int cn = n;
    int ans = 1;
    if (n == 1) {
        cout << "3\n";
        return;
    }
    while(n) {
        if (n % 2 == 1) break;
        ans *= 2;
        n /= 2;
    }
    if (cn == ans) ans += 1;
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
