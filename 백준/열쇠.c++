# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <string.h>
using namespace std;

# define MAX 100
vector<string> board;
string keys;
int N,M;
bool visited[MAX][MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

void clear() {
    board.clear();
    keys.clear();
    for (int i = 0; i < MAX; i++)
        memset(visited[i], 0, sizeof(bool)*MAX);
}

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

bool in_keys(char key) {
    for (char k : keys) {
        if (k == key) return true;
    }
    return false;
}

bool can_open(int r, int c) {
    if (visited[r][c]) return false;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!in_range(nr,nc)) return true;
        else if (visited[nr][nc]) return true;
    }
    return false;
}

int bfs(int r, int c) {
    int cnt = 0;
    queue<pair<int,int>> q;
    if (board[r][c] >= 'A' && board[r][c] <= 'Z' && !in_keys(board[r][c] + 32)) return 0;
    if (board[r][c] >= 'a' && board[r][c] <= 'z' && !in_keys(board[r][c])) {
        keys.push_back(board[r][c]);
        char door = board[r][c] - 32;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (board[j][k] == door && can_open(j,k)) {
                    q.push({j,k});
                    visited[j][k] = true;
                }
            }
        }
    }
    if (board[r][c] == '$') cnt++;
    q.push({r,c});
    visited[r][c] = true;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc] == '*') continue;

            char next = board[nr][nc];

            if (next == '$') {
                cnt++;
                q.push({nr,nc});
                visited[nr][nc] = true;
            }

            else if (next == '.') {
                q.push({nr,nc});
                visited[nr][nc] = true;
            }

            else if (next >= 'a' && next <= 'z') {
                q.push({nr,nc});
                visited[nr][nc] = true;

                if (in_keys(next)) continue;
                keys.push_back(next);

                char door = next - 32;
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < M; k++) {
                        if (board[j][k] == door && can_open(j,k)) {
                            q.push({j,k});
                            visited[j][k] = true;
                        }
                    }
                }
            }

            else if (next >= 'A' && next <= 'Z') {
                if (!in_keys(next+32)) continue;
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    return cnt;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            board.push_back(s);
        }
        cin >> keys;

        int result = 0;

        for (int i = 0; i < M; i++) {
            if (board[0][i] != '*' && !visited[0][i]) result += bfs(0,i);
            if (board[N-1][i] != '*' && !visited[N-1][i]) result += bfs(N-1,i);
        }

        for (int i = 0; i < N; i++) {
            if (board[i][0] != '*' && !visited[i][0]) result += bfs(i,0);
            if (board[i][M-1] != '*' && !visited[i][M-1]) result += bfs(i,M-1);
        }

        cout << result << "\n";
        clear();
    }
}