#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n,0),b;
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);

    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]) cnt++;
        else {
            if (cnt == 1) {
                cout << "-1\n";
                return;
            }
            b.push_back(cnt);
            cnt = 1;
        }
    }

    int sum = 1;
    for (int x : b) {
        cout << sum + x - 1 << " ";
        for (int i = sum; i < sum + x - 1; i++) cout << i << " ";
        sum += x;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
