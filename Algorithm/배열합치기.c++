#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<int> a(n,0), b(m,0), ans;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ai = 0, bi = 0;
    while (ai < n && bi < m) {
        if (a[ai] < b[bi]) ans.push_back(a[ai++]);
        else ans.push_back(b[bi++]);
    }

    while (ai < n) {
        ans.push_back(a[ai++]);
    }
    while (bi < m) {
        ans.push_back(b[bi++]);
    }

    for (int x : ans) {
        cout << x << " ";
    }
}