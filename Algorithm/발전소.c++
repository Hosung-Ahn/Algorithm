# include <iostream>
# include <bitset>
# include <string>
# include <string.h>
using namespace std;

# define MAX 16
# define INF 987654321
int dp[1 << MAX];
int cost[MAX][MAX] = {0,};
int N,P;

int min_cost(bitset<MAX> &visited, int idx) {
    int ret = INF;
    for (int i = 0; i < N; i++) {
        if (i == idx) continue;
        if (visited[i]) ret = min(ret, cost[i][idx]);
    }
    return ret;
}

int cal_dp_idx(const bitset<MAX> &visited) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) ret += 1 << i;
    }
    return ret;
}

int find_dp(bitset<MAX> &visited) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) cnt++;
    }
    if (cnt >= P) return 0;

    int dp_idx = cal_dp_idx(visited);
    if (dp[dp_idx] != -1) return dp[dp_idx];

    int result = INF;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            result = min(result, min_cost(visited, i) + find_dp(visited));
            visited[i] = 0;
        }
    }

    dp[dp_idx] = result;
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);

    bitset<MAX> visited;
    visited.reset();

    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'Y') visited[i] = 1;
    }
    cin >> P;

    memset(dp, -1, sizeof(int) * (1<<MAX));

    int result = find_dp(visited);

    if (result >= INF) cout << -1;
    else cout << result;





}