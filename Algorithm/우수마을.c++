# include <iostream> 
# include <vector>
using namespace std;

# define MAX 10001
int arr[MAX];
bool visited[MAX] = {0,};
vector<int> dist[MAX];
int dp[MAX][2];
int N;

void dfs(int cur) {
    dp[cur][0] = 0;
    dp[cur][1] = arr[cur];

    visited[cur] = true;

    for (int i = 0; i < dist[cur].size(); i++) {
        int next = dist[cur][i];
        if (visited[next]) continue;
        dfs(next);

        dp[cur][0] += max(dp[next][0], dp[next][1]);
        dp[cur][1] += dp[next][0];
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N-1; i++){
        int s,e; scanf("%d %d", &s, &e);
        dist[s].push_back(e);
        dist[e].push_back(s);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << endl;


}