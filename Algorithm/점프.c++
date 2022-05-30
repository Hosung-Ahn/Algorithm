# include <iostream>
using namespace std;

# define MAX 101
# define ll long long

int board[MAX][MAX];
ll dp[MAX][MAX] = {0,}; 
int n;

ll count_path(int r, int c) {
    if (dp[r][c] != 0) return dp[r][c];
    if (board[r][c] == 0) return 0;

    ll result = 0;
    if (r + board[r][c] <= n)
        result += count_path(r + board[r][c], c);
    if (c + board[r][c] <= n) 
        result += count_path(r, c + board[r][c]);

    dp[r][c] = result;
    return result;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            scanf("%d", &board[i][j]);

    dp[n][n] = 1;

    ll result = count_path(1,1);

    cout << result << endl;
}