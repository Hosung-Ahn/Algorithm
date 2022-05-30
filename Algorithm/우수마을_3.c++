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

int find_dp(int cur, int great) {
    
    if (dp[cur][great] != -1) return dp[cur][great];

    visited[cur] = true;

    int result = 0;
    if (great == 1) result = pp[cur];

    for (int next : dist[cur]) {
        if (visited[next]) continue;

        switch (great) {
            case 0 :
            result += max(find_dp(next, 0), find_dp(next,1));
            break;
            case 1 :
            result += find_dp(next,0);
        }
    }

    cout << "cur, great = " << cur << " " << great << " result = " << result << endl;

    dp[cur][great] = result;
    return result;
}

int main() {
    cin >> N;

    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*2);

    for (int i = 1; i <= N; i++)
        scanf("%d", &pp[i]);

    for (int i = 0; i < N-1; i++){
        int s,e; scanf("%d %d", &s, &e);
        dist[s].push_back(e);
        dist[e].push_back(s);
    }

    cout << find_dp(1,1) << endl;
    
}