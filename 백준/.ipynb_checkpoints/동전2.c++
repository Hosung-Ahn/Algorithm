# include <iostream>
using namespace std;
# define INF 100000

int dp[10001] = {0, };
int n,k;
int coins[100];

int find_dp(int money) {
    if (dp[money] != 0) return dp[money];
    if (money == 0) return 0;

    int result = INF;
    for (int coin = 0; coin < n; coin++) {
        if (money - coins[coin] < 0) continue;
        result = min(result, find_dp(money - coins[coin]) + 1 );
    }

    dp[money] = result;
    return result;
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", &coins[i]);

    int result = find_dp(k);

    if (result >= INF) cout << -1 << endl;
    else cout << result << endl;
}