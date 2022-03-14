# include <iostream>
# include <string.h>
using namespace std;

# define MAX 32
# define ll long long
int board[MAX][MAX] = {0,};
ll dp[MAX][MAX][3];
int N;

ll find_dp(int r, int c, int d) {
    if (dp[r][c][d] != -1) return dp[r][c][d];

    ll result = 0;

    switch(d) {
        case 0 :
            if (c == 0) return 0;
            if (board[r][c] == 1 || board[r][c-1] == 1) return 0;
            result = find_dp(r,c-1,0) + find_dp(r,c-1,2);
        break;

        case 1 :
            if (r == 0) return 0;
            if (board[r][c] == 1 || board[r-1][c] == 1) return 0;
            result = find_dp(r-1,c,1) + find_dp(r-1,c,2);
        break;

        case 2 :
            if (r == 0 || c == 0) return 0;
            if (board[r][c] == 1 || board[r-1][c] == 1 
            || board[r][c-1] == 1 || board[r-1][c-1] == 1) return 0;
            result += find_dp(r-1,c-1,0) + find_dp(r-1,c-1,1) + find_dp(r-1,c-1,2);
        break;
    }
    dp[r][c][d] = result;
    return result;
}

int main() {
    for (int r = 0; r < MAX; r++) {
        for (int c = 0; c < MAX; c++) {
            memset(dp[r][c], -1, sizeof(ll)*3);
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    dp[0][1][0] = 1;
    cout << find_dp(N-1,N-1,0) + find_dp(N-1,N-1,1) + find_dp(N-1,N-1,2);

    for (int i = 0; i < 5; i++) {
        
    }
}