#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 100
#define INF 987654321

struct Point {
    int r,c,d;
    Point(int r, int c, int d) : r(r), c(c), d(d) { }
};

vector<string> board;
int R,C;
int cnt[MAX][MAX][4];
int dr[] = {-1,0,1,0}; 
int dc[] = {0,1,0,-1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void bfs(int sr, int sc) {
    queue<Point> q;
    for (int i = 0; i < 4; i++) {
        cnt[sr][sc][i] = 0;
    }
    for (int d = 0; d < 4; d++) {
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if (!in_range(nr,nc) || board[nr][nc] == '*') continue;
        cnt[nr][nc][d] = 0;
        q.push(Point(nr,nc,d));
    }

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cd = q.front().d;
        q.pop();

        // cout << cr << " " << cc << " " << cd << " " << cnt[cr][cc][cd] << endl;
        if (board[cr][cc] == 'C') continue;

        for (int i = -1; i <= 1; i++) {
            int nd = (cd+i) % 4;
            if (nd < 0) nd += 4;
            int nr = cr + dr[nd];
            int nc = cc + dc[nd];

            int next_cnt = cnt[cr][cc][cd] + abs(i);

            if (!in_range(nr,nc) || board[nr][nc] == '*' || cnt[nr][nc][nd] <= next_cnt) continue;

            // if (board[nr][nc] == 'C') cout << next_cnt << endl;
            cnt[nr][nc][nd] = next_cnt;
            q.push(Point(nr,nc,nd));
        }
    }
}

int main() {
    cin >> C >> R;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int sr, sc, er, ec;
    bool first = true;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'C' && first) {
                sr = r;
                sc = c;
                first = false;
                continue;
            }
            if (board[r][c] == 'C' && !first) {
                er = r;
                ec = c;
                break;
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            for (int d = 0; d < 4; d++) {
                cnt[r][c][d] = INF;
            }
        }
    }

    bfs(sr,sc);

    int result = INF;
    for (int d = 0; d < 4; d++) {
        result = min(result, cnt[er][ec][d]);
    }

    cout << result;
}