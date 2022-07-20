#include<iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 2 != 0) {
        cout << "-1\n";
        return;
    }
    n /= 2;
    int ans = 0, tmp = 1;
    while(n) {
        if (n % 2 == 1) {
            ans += tmp;
        }
        tmp *= 2;
        n /= 2;
    }
    cout << ans << " " << ans << " " << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
