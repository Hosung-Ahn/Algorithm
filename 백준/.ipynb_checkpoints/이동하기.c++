# include <iostream>
# include <string.h>
using namespace std;
# define MAX 1001

int board[MAX][MAX];
int dp[MAX][MAX];
int N, M;

bool not_in_range(int r, int c) {
    if ( r < 1 || r > N || c < 0 || c > M) return true;
    return false;
}

int find_dp(int r, int c){
    if (not_in_range(r,c)) return 0;

    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = board[r][c] + max(find_dp(r-1,c), find_dp(r,c-1));
    return dp[r][c];
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) 
            scanf("%d", &board[i][j]);
        

    for (int i = 0; i< MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);
    


    cout << find_dp(N,M) << endl;
}