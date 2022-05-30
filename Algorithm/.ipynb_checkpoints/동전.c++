# include <iostream>
# include <string.h>
using namespace std;

# define MAX 10001

int dp[MAX] = {0, };

void find_dp(int coin){
    for (int i = coin; i <= MAX; i++) {
        dp[i] += dp[i-coin];
    }
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) { 

        dp[0] = 1;
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int coin; cin >> coin;
            find_dp(coin);
        }

        int result; cin >> result;
        cout << dp[result] << endl;
        memset(dp, 0, sizeof(int)*MAX);
    }
}