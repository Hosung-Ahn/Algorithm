#include<iostream>
#include<string>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    if (n == 2) {
        if (k == 0) {
            cout << 10*(s[0]-'0') + s[1]-'0' << "\n";
        }
        else {
            cout << min(10*(s[0]-'0') + s[1]-'0', 10*(s[1]-'0') + s[0]-'0') << "\n";
        }
    }
    else {
        int x = 0;
        for (int i = 0; i < n-1; i++) {
            x += 10*(s[i]-'0') + s[i+1]-'0';
        }
        int l = 1, r = n - 2;
        while(l < n-1 && s[l] == '0') {
            l++;
        }

        while(r > 0 && s[r] == '0') {
            r--;
        }

        if (s[0] == '0' && s[n-1] == '0') {
            if (l == n-1) {
                cout << x << "\n";
                return;
            }
            if (l == r) {
                if (n-r-1 <= k) {
                    cout << x - 10 << "\n";
                }
                else if (l <= k) {
                    cout << x - 1 << "\n";
                }
                else {
                    cout << x << "\n";
                }
                return;
            }
            else {
                if (n-r-1 + l <= k) {
                    cout << x - 11 << "\n";
                }
                else if (n-r-1 <= k) {
                    cout << x - 10 << "\n";
                }
                else if (l <= k) {
                    cout << x - 1 << "\n";
                }
                else {
                    cout << x << "\n";
                }
                return;
            }
        }
        else if (s[0] == '1' && s[n-1] == '0') {
            if (l == n-1) {
                if (n-1 <= k) cout << "1\n";
                else cout << x << "\n";
                return;
            }
            if (n-r-1 <= k) {
                cout << x - 10 << "\n";
                return;
            }
            else {
                cout << x << "\n";
                return;
            }
        }
        else if (s[0] == '0' && s[n-1] == '1') {
            if (l == n-1) {
                cout << x << "\n";
                return;
            }
            if (l <= k) {
                cout << x - 1 << "\n";
                return;
            }
            else {
                cout << x << "\n";
                return;
            }
        }
        else {
            cout << x << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
