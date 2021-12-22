# include <iostream>
using namespace std;

# define MAX 500

int board[MAX][MAX];
int dp[MAX][MAX] = {0,};
int m,n;

int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n) return false;
    return true;
}

int find_dp(int r, int c) {
    if ( r == m-1 && c == n-1) return 1;
    if ( dp[r][c] != 0 ) return dp[r][c];

    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (in_range(nr,nc) && board[nr][nc] < board[r][c]) {
            dp[nr][nc] = find_dp(nr,nc);
            result += dp[nr][nc];
        }
    }

    dp[r][c] = result;
    return dp[r][c];
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++)
            scanf("%d", &board[i][j]);

    cout << find_dp(0,0) << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}