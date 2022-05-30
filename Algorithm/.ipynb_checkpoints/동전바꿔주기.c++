# include <iostream> 
# include <vector>
# include <string.h>
using namespace std;

# define MAX 10001

int dp[100][MAX];

vector<pair<int,int>> coins;
int T, K; 

int find_dp(int idx, int money) {
    if (idx >= K) {
        if (money == 0) return 1;
        else return 0;
    }
    if (money < 0) return 0;

    if (dp[idx][money] != -1) return dp[idx][money];

    int coin = coins[idx].first;
    int cnt = coins[idx].second;

    int result = 0;
    for (int i = 0; i <= cnt; i++) {
        result += find_dp(idx+1, money - coin * i);
    }
    dp[idx][money] = result;

    return result;
}

int main() {
    cin >> T >> K;

    for (int i = 0; i < K; i++) {
        int coin, n; scanf("%d %d", &coin, &n);
        coins.push_back({coin,n});
    }

    for (int i = 0; i < 100; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);
    cout << find_dp(0,T) << endl;

    
}