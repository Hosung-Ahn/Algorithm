#include <iostream>
#include <string>
using namespace std;

int ans = 1;
int dp[2500][2500] = {0,};

bool find_dp(int l, int r, const string &s) {
    if (dp[l][r] != 0) {
        return dp[l][r] == 1 ? true : false;
    }    
    if (r-l+1 <= 1) return true;

    if (s[l] == s[r] && find_dp(l+1,r-1,s)) {
        ans = max(ans, r-l+1);
        dp[l][r] = 1;
        return true;
    } 
    else {
        find_dp(l+1,r,s);
        find_dp(l,r-1,s);
        dp[l][r] = 2;
        return false;
    }
}

int solution(string s)
{
    find_dp(0, s.size()-1, s);
    return ans;
}

int main() {
    cout << solution("abaa");
}