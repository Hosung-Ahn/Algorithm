# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <string.h>
using namespace std;
# define MAX 1500
# define INF 987654321

vector<string> board;
int visited[MAX][MAX];
int visited_L[MAX][MAX];
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void bfs_ice(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) { 
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (board[cr][cc] == '.' || board[cr][cc] == 'L') visited[cr][cc] = 0;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc)) continue;

            if (board[nr][nc] == '.' || board[nr][nc] == 'L') {
                if (visited[nr][nc] <= visited[cr][cc]) continue;
                visited[nr][nc] = visited[cr][cc];
                q.push({nr,nc});
            }

            else {
                if (visited[nr][nc] <= visited[cr][cc] + 1) continue;
                visited[nr][nc] = visited[cr][cc] + 1;
                q.push({nr,nc});
            }
        }
    }
}

int bfs_L(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited_L[r][c] = 0; 

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc)) continue;

            int next_cnt = max(visited[nr][nc], visited_L[cr][cc]);
            if (visited_L[nr][nc] <= next_cnt) continue;
            visited_L[nr][nc] = next_cnt;
            q.push({nr,nc});
        }
    }
    int ret = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'L' && !(i == r && j == c)) {
                ret = visited_L[i][j];
                break;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int lr,lc;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            visited[r][c] = INF;
            visited_L[r][c] = INF;
            if (board[r][c] == 'L') {
                lr = r;
                lc = c;
            }
        }
    }

    bfs_ice(lr,lc);
    cout << bfs_L(lr,lc);

}