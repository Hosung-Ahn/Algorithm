# include <iostream>
# include <string.h>
using namespace std;

# define MAX 16
# define INF 987654321

int go[MAX][MAX] = {0,};
int dp[MAX][1 << MAX];
int N;

int DFS(int cur, int visited) {
    if (visited == (1 << N) -1) {
        if (go[cur][0] == 0) return INF;
        else return go[cur][0];
    }

    if (dp[cur][visited] != -1) return dp[cur][visited];

    int result = INF;
    for (int next = 0; next < N; next++) {
        if (go[cur][next] == 0 || (visited & (1 << next))) continue;

        result = min(result, go[cur][next] + DFS(next, visited + (1 << next)));
    }
    dp[cur][visited] = result;
    return result;
}

int main() {
    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*(1 << MAX));
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &go[i][j]);

    cout << DFS(0,1);
    
}