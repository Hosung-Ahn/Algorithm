# include <iostream>
# include <string.h>
using namespace std;

# define MAX 1000
# define MOD 1000000007
int dp[MAX][MAX];
int N,M;

int dr[] = {1,0,1};
int dc[] = {0,1,1};

int find_dp(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return 0;
    if (dp[r][c] != -1) return dp[r][c];
    if (r == N-1 && c == M-1) return 1;

    int result = 0;
    for (int i = 0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        result += find_dp(nr,nc);
        result %= MOD;
    }
    dp[r][c] = result;
    return result;
}


int main() {
    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*MAX);
    cin >> N >> M;
    cout << find_dp(0,0) << endl; 
}