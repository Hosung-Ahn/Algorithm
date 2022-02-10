# include <iostream>
# include <string>
# include <vector>
using namespace std;

# define MAX 50

vector<string> board;
int N,M;
int dp[MAX][MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
bool visited[MAX][MAX] = {0,};
bool is_cycle = false;

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

int find_dp(int r, int c) {
    if (dp[r][c] != 0) return dp[r][c];

    int result = 0;
    for (int i = 0; i < 4; i++){
        int nr = r + dr[i] * (board[r][c] - '0');
        int nc = c + dc[i] * (board[r][c] - '0');
        
        if (!in_range(nr,nc) || board[nr][nc] == 'H') continue;
        if (visited[nr][nc]) {
            is_cycle = true;
            return 0;
        }

        visited[nr][nc] = true;
        result = max(result, find_dp(nr,nc));
        visited[nr][nc] = false;
    }
    dp[r][c] = result + 1;
    return dp[r][c];
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int result = find_dp(0,0);
    
    if (is_cycle) cout << -1;
    else cout << result;

}

