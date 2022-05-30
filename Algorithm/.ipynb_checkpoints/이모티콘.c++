# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 10001

int dp[MAX][MAX] = {0, };
int N;

int find_dp() {
    queue<pair<int,int>> bfs;
    bfs.push(make_pair(1,0));
    dp[1][0] = 0; 

    while (!bfs.empty()) {
        int n = bfs.front().first;
        int k = bfs.front().second;
        bfs.pop();
        int cur = dp[n][k];

        if (n == N) return cur;

        if (dp[n][n] == -1) {
            dp[n][n] = cur + 1;
            bfs.push(make_pair(n,n));
        }
        if (dp[n+k][k] == -1) {
            dp[n+k][k] = cur + 1;
            bfs.push(make_pair(n+k,k));
        }
        if (dp[n-1][k] == -1 && n-1 != 0) {
            dp[n-1][k] = cur + 1;
            bfs.push(make_pair(n-1,k));
        }

    }

    return 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    cout << find_dp() << endl;
}