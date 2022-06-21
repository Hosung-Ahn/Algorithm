#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000

void solve() {
    int n; cin >> n;
    vector<int> arr;
    for (int i = 0; i <= n; i++) arr.push_back(1);

    string s; cin>> s;
    vector<int> ans;
    if (s[0] == '9') {
        for (int i = n-1; i >= 0; i--) {
            int cur = arr[i+1] - (s[i]-'0');
            if (cur < 0) {
                arr[i]--;
                cur += 10;
            }
            ans.push_back(cur);
        }
        for (int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << "\n";
        return;
    }

    int i = 0;
    for (; i < s.size(); i++) {
        cout << '9'-s[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T;cin>> T;
    while(T--) {
        solve();
    }
}