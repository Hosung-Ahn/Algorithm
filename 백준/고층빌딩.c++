# include <iostream>
# include <string.h>
using namespace std;

# define MAX 101
# define MOD 1000000007
# define ll long long

int dp[MAX][MAX][MAX];

ll find_dp(int i, int n, int k) {
    if(n > i || k > i || i < 1 || n < 0 || k < 0) return 0;
    if (dp[i][n][k] != -1) return dp[i][n][k];

    ll result = (find_dp(i-1,n,k-1) + find_dp(i-1,n-1,k) + find_dp(i-1,n,k) * (i-2)) % MOD;
    dp[i][n][k] = result;
    return result; 
}

int main() {
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++) { 
            memset(dp[i][j], -1, sizeof(int)*MAX);
        }
    }
    dp[1][1][1] = 1;
    for (int i = 2; i < MAX; i++) {
        dp[i][1][1] = 0;
        dp[i][i][1] = 1;
        dp[i][1][i] = 1;
    }

    int i,n,k; cin >> i >> n >> k;
    cout << find_dp(i,n,k);
}