# include <iostream> 
# include <string.h>
using namespace std;
# define MAX 1001
# define MOD 1000000003
int dp[MAX][MAX] ={0,};

int main() {
    int n,k; cin >> n >> k;
    
    for (int n = 1; n < MAX; n++)
        dp[n][1] = n;

    for (int n = 2; n < MAX; n++) {
        for (int k = 2; k < MAX; k++) {
            dp[n][k] = (dp[n-1][k] + dp[n-2][k-1]) % MOD; 
        }
    }

    if (k == 1) cout << dp[n][k];
    else cout << (dp[n-1][k] + dp[n-3][k-1]) % MOD;
}