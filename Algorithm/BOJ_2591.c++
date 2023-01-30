#include <iostream>
#include <string>
#include <cstring>
using namespace std; 
#define ll long long
ll dp[40];
string s;

int cal_n(int idx) {
    int ret = 0;
    ret += s[idx]-'0';
    ret *= 10;
    ret += s[idx+1]-'0';
    return ret;
}

ll find_dp(int idx) {
    ll &ret = dp[idx];
    if (ret != -1) return ret;
    if (s[idx] == '0') return 0;
    if (idx == s.size()) return 1;
    ret = 0;
    if (idx != s.size()-1 && cal_n(idx) <= 34) {
        ret += find_dp(idx+2);
    }
    ret += find_dp(idx+1);
    return ret;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << find_dp(0);
}