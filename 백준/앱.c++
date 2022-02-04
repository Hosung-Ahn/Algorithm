# include <iostream>
# include <vector>
using namespace std;

# define MAX 100
int value[MAX] = {0,};
int cost[MAX] = {0,};
vector<int> dp(10001, 0);

int main() {
    int N,M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        scanf("%d", &value[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &cost[i]);

    for (int i = 0; i < N; i++) {
        int cur_value = value[i];
        int cur_cost = cost[i];
        
        vector<int> dp_copy = dp;
        for (int j = cur_cost; j <= 10000; j++) {
            dp[j] = max(dp[j], dp_copy[j - cur_cost] + cur_value);
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= M) {
            cout << i;
            break;
        }
    }
}