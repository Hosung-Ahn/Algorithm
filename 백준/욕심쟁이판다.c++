# include <iostream>
using namespace std;

# define MAX 500

int board[MAX][MAX];
int dp[MAX][MAX] = {0,};
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true; 
}

int find_dp(int r, int c) {
    if (dp[r][c] != 0) return dp[r][c];
    dp[r][c] = 1;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!in_range(nr,nc) || board[nr][nc] <= board[r][c]) 
            continue;
        result = max(result, find_dp(nr,nc));
    }
    dp[r][c] = result + 1;

    return dp[r][c];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int result = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            result = max(result, find_dp(r,c));
        }
    }
    cout << result;
}
