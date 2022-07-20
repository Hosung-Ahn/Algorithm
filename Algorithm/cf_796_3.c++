#include<iostream>
#include<string>
using namespace std;

void solve() {
    int n; cin >> n;
    int alpha[26] = {0,};
    for (int i = 0; i <= 2*n; i++) {
        string s; cin >> s;
        for (char c : s) {
            alpha[c-'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 == 1) {
            cout << (char)('a' + i) << "\n";
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
