# include <iostream>
using namespace std;

# define MAX 15
int N;
int board[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
bool choosed[MAX] = {0,};
int dp[MAX][10] = {0,};


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &board[i][j]);
        }
    }


}