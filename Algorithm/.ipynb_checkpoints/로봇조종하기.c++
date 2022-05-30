# include <iostream>
using namespace std;

# define MAX 1000
# define INF -1000000000

int board[MAX][MAX];
int dp[3][MAX][MAX];
int N,M;

int find_dp(int dir, int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return INF;
    if (dp[dir][r][c] != INF) return dp[dir][r][c];
    if (r == N-1 && c == M-1) return board[r][c];

    int result = 0;
    switch (dir) {
        case 0 :
        result = max(find_dp(0,r+1,c), max(find_dp(1,r,c+1), find_dp(2, r,c-1)));
        break;
        case 1 : 
        result = max(find_dp(1, r,c+1), find_dp(0, r+1,c));
        break;
        case 2 :
        result = max(find_dp(2, r,c-1), find_dp(0, r+1,c));
        break;
    }
    result += board[r][c];
    dp[dir][r][c] = result;

    return result;
}

int main() {
    cin >> N >> M;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            scanf("%d", &board[r][c]);

    for (int d = 0; d < 3; d++) 
        for (int r = 0; r < MAX; r++)
            for (int c = 0; c < MAX; c++)
                dp[d][r][c] = INF;

    cout << find_dp(0,0,0) << endl;
}