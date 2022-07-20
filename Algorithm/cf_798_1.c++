#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve() {
    string a,b,ans;
    int n,m,k; cin >> n >> m >> k;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ai = 0, bi = 0, ac = 0, bc = 0;
    bool A = true;
    while (ai < n && bi < m) {
        if (a[ai] < b[bi]) A = true;
        else A = false;

        if (ac == k) {
            A = false;
        }
        else if (bc == k) {
            A = true;
        }

        if (A) {
            ans.push_back(a[ai++]);
            ac++;
            bc = 0;
        }
        else {
            ans.push_back(b[bi++]);
            bc++;
            ac = 0;
        }
        // cout << ac << " " << bc << endl;
    }
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
