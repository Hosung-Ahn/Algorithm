# include <iostream>
using namespace std;

# define MAX 1001
# define MOD 10007

int dp[MAX] = {0,};

int main() {
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < MAX; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
        dp[i] %= MOD;
    }

    int n; cin >> n;
    cout << dp[n];
}