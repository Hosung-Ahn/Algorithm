# include <iostream>
using namespace std;

# define MAX 15
int N;
int board[MAX][MAX] = {0,};
int dp[1 << 15][MAX][10] = {0,};

int find_dp(int visited, int n, int p) {
    int &result = dp[visited][n][p];
    if (result != 0) return result;

    result = 1;

    for (int nn = 0; nn < N; nn++) {
        int np = board[n][nn];
        if (np >= p && !(visited & (1 << nn))) {
            result = max(result, find_dp(visited + (1 << nn), nn, np) + 1);
        }
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    cout << find_dp(1,0,0);
}
