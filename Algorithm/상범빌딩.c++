#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
# define MAX 30
# define INF 987654321

struct Point {
    int l,r,c;
    Point(int l, int r, int c) : l(l), r(r), c(c) {}
};

vector<vector<string>> board;
int cnt[MAX][MAX][MAX];
int L,R,C;
int dr[] = {-1,0,1,0,0,0};
int dc[] = {0,-1,0,1,0,0};
int dl[] = {0,0,0,0,1,-1};

bool in_range(int l, int r, int c) {
    if (l < 0 || l >= L || r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void bfs(Point s) {
    cnt[s.l][s.r][s.c] = 0;
    queue<Point> q;
    q.push(s);
    while (!q.empty()) {
        int cl = q.front().l;
        int cr = q.front().r;
        int cc = q.front().c;
        q.pop();

        if (board[cl][cr][cc] == 'E') {
            cout << "Escaped in " << cnt[cl][cr][cc] << " minute(s).\n";
            return;
        }

        for (int i = 0; i < 6; i++) {
            int nl = cl + dl[i];
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nl,nr,nc) || cnt[nl][nr][nc] != -1 || board[nl][nr][nc] == '#') continue;
            cnt[nl][nr][nc] = cnt[cl][cr][cc] + 1;
            q.push(Point(nl,nr,nc));
        }
    }
    cout << "Trapped!\n";
}


int main() {
    while(true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        board.clear();
        
        for (int l = 0; l < L; l++) {
            vector<string> floor;
            for (int r = 0; r < R; r++) {
                string s; cin >> s;
                floor.push_back(s);
            }
            board.push_back(floor);
        }

        int sl,sr,sc;
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (board[l][r][c] == 'S') {
                        sl = l;
                        sr = r;
                        sc = c;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                memset(cnt[i][j], -1, sizeof(int)*MAX);
            }
        }

        bfs(Point(sl,sr,sc));
    }


}