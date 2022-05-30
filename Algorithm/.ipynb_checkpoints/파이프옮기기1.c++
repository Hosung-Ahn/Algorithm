# include <iostream>
# include <string.h>
using namespace std;

# define MAX 17

int dp[3][MAX][MAX];
int board[MAX][MAX];
int n;

bool in_range(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > n) return false;
    return true;
}

int find_dp(int rotation, int r, int c) {
    if (!in_range(r,c)) return 0;

    switch (rotation) {
        case 0:
        case 1:
        if (board[r][c] == 1) return 0;
        break;

        case 2:
        if (board[r][c] == 1 || board[r+1][c] == 1 || board[r][c+1] == 1) return 0;
        break;
    }

    if (r == 1 && c == 1 && rotation == 0) return 1;

    if (dp[rotation][r][c] != -1) return dp[rotation][r][c];

    int result = 0;
    switch (rotation) {
        case 0:
        result += find_dp(0,r,c-1);
        result += find_dp(2,r-1,c-1);
        break;

        case 1:
        result += find_dp(1,r-1,c);
        result += find_dp(2,r-1,c-1);
        break;

        case 2:
        result += find_dp(0,r,c-1);
        result += find_dp(1,r-1,c);
        result += find_dp(2,r-1,c-1);
        break;
    }
    dp[rotation][r][c] = result;
    return result;
}

int main() {
    cin >> n;
    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= n; c++)
            scanf("%d", &board[r][c]);

    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < MAX; j++)
            memset(dp[i][j], -1, sizeof(int)*MAX);

    if (board[n][n] == 1) cout << 0 << endl;
    else { 
        int result = 0;
        result += find_dp(0, n, n-1);
        result += find_dp(1, n-1,n);
        result += find_dp(2,n-1,n-1);

        cout << result << endl;
    }
}