#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX 10000
#define INF 987654321
int dp[MAX] = {0,};

bool all_same(int idx, int next_idx, const string &s) {
    int x = s[idx];
    for(int i=idx;i<next_idx;i++) {
        if (s[i] != x) return false;
    }
    return true;
}

bool mono_plus(int idx, int next_idx, const string&s) {
    for(int i=idx+1;i<next_idx;i++) {
        if (s[i]+1 != s[i-1]) return false;
    }
    return true;
}

bool mono_minus(int idx, int next_idx, const string&s) {
    for(int i=idx+1;i<next_idx;i++) {
        if (s[i]-1 != s[i-1]) return false;
    }
    return true;
}

bool repeat(int idx, int next_idx, const string &s) {
    char num[2];
    if (idx % 2 == 0) {
        num[0] = s[idx];
        num[1] = s[idx+1];
    }
    else {
        num[0] = s[idx+1];
        num[1] = s[idx+2];
    }

    for(int i=idx;i<next_idx;i++) {
        if (s[i] != num[i%2]) return false;
    }
    return true;
}

bool sequence(int idx, int next_idx, const string &s) {
    int a = s[idx]-'0';
    int d = s[idx+1]-'0' - a;
    for(int i=idx;i<next_idx;i++) {
        int x = a + d*(i-idx);
        if (s[i]-'0' != x) return false;
    }
    return true;
}

int cal(int idx, int next_idx, const string &s) {
    if (all_same(idx, next_idx, s)) return 1;
    if (mono_plus(idx, next_idx, s) || mono_minus(idx, next_idx, s)) return 2;
    if (repeat(idx, next_idx, s)) return 4;
    if (sequence(idx, next_idx, s)) return 5;
    return 10;
}

int find_dp(int idx, const string &s) {
    if (idx == s.size()) return 0;
    if (idx > s.size()) return INF;
    int &ret = dp[idx];
    if (ret != -1) return ret;

    ret = INF;
    for(int next_idx = idx+3; next_idx < idx+6; next_idx++) {
        ret = min(ret, cal(idx, next_idx, s) + find_dp(next_idx, s));
    }
    return ret;
}

void solve() {
    string s; cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << find_dp(0, s) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int T; cin >> T;
    while(T--) {
        solve();
    }   
}