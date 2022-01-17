# include <iostream>
# include <vector>
# include <string.h>
using namespace std;

# define MAX 10001

int pp[MAX] = {0, };
vector<int> dist[MAX];
int visited[MAX] = {0,};
int dp[MAX][2];
int N;

void dfs(int cur) {
    visited[cur] = true;

    // 끝 노드는 for 문이 실행되지 않을 것이기 때문에 for문 밖에서 dp를 지정해준다.
    dp[cur][0] = 0;
    dp[cur][1] = pp[cur];

    for (int next : dist[cur]) {
        if(visited[next]) continue;
        dfs(next);

        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &pp[i]);

    for (int i = 0; i < N-1; i++){
        int s,e; scanf("%d %d", &s, &e);
        dist[s].push_back(e);
        dist[e].push_back(s);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << endl;

    
}