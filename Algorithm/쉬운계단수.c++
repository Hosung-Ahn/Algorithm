# include <iostream>
using namespace std;

# define MAX 1000
# define MOD 1000000000

int dp[10][MAX+1] = {0,};

int find_dp(int first, int n) {
    if (first < 0 || first > 9) return 0;
    if (dp[first][n] != 0) return dp[first][n];

    int result = 0;
    result += find_dp(first-1, n-1);
    result %= MOD;
    result += find_dp(first+1, n-1);
    result %= MOD;

    dp[first][n] = result;
    return result;
}

int main() {
    for (int i = 0; i <= 9; i++) {
        dp[i][1] = 1;
    }

    int n; cin >> n;

    int result = 0;
    for (int i = 1; i <= 9; i++) {
        result += find_dp(i, n);
        result %= MOD;
    }

    cout << result << endl;
}