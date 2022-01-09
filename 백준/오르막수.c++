# include <iostream>
using namespace std;

# define MAX 1000
# define MOD 10007

int dp[10][MAX+1] = {0, };

int find_dp(int first, int n) {
    if (dp[first][n] != 0) return dp[first][n];

    int result = 0;

    for (int next = first; next <= 9; next++) {
        result += find_dp(next, n-1);
        result %= MOD;
    }

    dp[first][n] = result;

    return result;
}

int main() {
    for (int i = 0; i <= 9; i++) dp[i][1] = 1;

    int n; cin >> n;

    int result = 0; 
    for (int i = 0; i <= 9; i++) {
        result += find_dp(i,n);
        result %= MOD;
    }

    cout << result << endl;
}