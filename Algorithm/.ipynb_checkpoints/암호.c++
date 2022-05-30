# include <iostream>
# include <string>
using namespace std;

# define MAX 5000
# define MOD 1000000

int dp[MAX+1] = {0, };

int find_dp(string s) {
    if (s[0] == '0') return 0; 
    if (s.size() <= 1) return 1;
    if (dp[s.size()] != 0) return dp[s.size()];

    int result = 0;

    if (s[0] == '1' || (s[0] == '2' && s[1] >= '0' && s[1] <= '6') ) {
        result += find_dp(s.substr(1));
        result += find_dp(s.substr(2));
        result %= MOD;
        dp[s.size()] = result;
        return result;
    }

    result += find_dp(s.substr(1));
    dp[s.size()] = result;
    return result;
}
    
int main() {
    string s; cin >> s;
    cout << find_dp(s) << endl;
}

