# include <iostream>
# include <vector>
# include <string>
using namespace std;

# define MAX 1000

vector<string> board;
int N,M;
int dp[MAX][MAX] = {0,};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

int find_dp(int r, int c) {
    if (!in_range(r,c) || board[r][c] == '0') return 0;
    if (dp[r][c] != 0) return dp[r][c];

    int result = min(find_dp(r,c+1), min(find_dp(r+1,c+1), find_dp(r+1,c))) + 1;
    dp[r][c] = result;
    return result;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int max_x = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == '1') {
                int x = find_dp(r,c);
                if (x > max_x) max_x = x;
            }
        }
    }

    cout << max_x * max_x;
}