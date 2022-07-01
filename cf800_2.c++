#include<iostream>
#include<string>
using namespace std;
#define ll long long

void solve(){
    int n; string s; cin >> n >> s;
    ll result = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) result += i+1;
        else result += 1;
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}