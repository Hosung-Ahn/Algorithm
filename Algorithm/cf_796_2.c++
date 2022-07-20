#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    int even_cnt = 0, odd_cnt = 0;
    int min_odd = 987654321;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            even_cnt++;
            int tmp_odd = 0;
            while (x % 2 == 0) {
                tmp_odd++;
                x /= 2;
            }
            min_odd = min(min_odd, tmp_odd);
        }
        else {
            odd_cnt++;
        }
    }
    if (odd_cnt > 0) cout << even_cnt << "\n";
    else {
        cout << min_odd + even_cnt-1 << "\n";
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
