#include <iostream>
#include <string> 
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
bool dp[MAX][MAX] = {0,};
vector<string> ans;

string wild, file;
bool res = false;

void find_dp(int i, int k) {
    if (i == wild.size() && k == file.size()) {
        res = true;
        return;
    }
    if (i == wild.size()) return;
    if (k == file.size() && wild[i] != '*') return;
    if (dp[i][k]) return;
    dp[i][k] = true;

    if (wild[i] == '*') {
        for(int nk=k; nk<=file.size(); nk++) {
            find_dp(i+1,nk);
        }
    }
    else if (wild[i] == '?') find_dp(i+1, k+1);
    else {
        if (wild[i] == file[k]) find_dp(i+1,k+1);
        return;
    }
}

void solve() {
    cin >> wild;
    ans.clear();

    int N; cin >> N;
    for(int i=0;i<N;i++) {
        memset(dp, 0, sizeof(dp));
        res = false;
        cin >> file;
        find_dp(0,0);
        if (res == true) ans.push_back(file);
    }

    sort(ans.begin(), ans.end());
    for(string s : ans) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}