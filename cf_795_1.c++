#include<iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    int even_cnt = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x%2 == 0) even_cnt++;
    }
    cout << min(even_cnt, n - even_cnt) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
