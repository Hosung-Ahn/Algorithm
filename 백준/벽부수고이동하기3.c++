# include <iostream>
# include <queue>
# define MAX 1001

using namespace std;

int N,M;
int d[2][MAX][MAX] = {0,};
int wall[MAX][MAX];

int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};

struct point {
    int r,c;
    int breaked;
    point(int r, int c, int b) : r(r), c(c), breaked(b) { }
};

void bfs() {
    d[0][1][1] = 1;
    queue<point> q;
    q.push(point(1,1,0));
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int breaked = q.front().breaked;
        q.pop();

        if (r == N && c == M) {
            cout << d[breaked][r][c] << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;

            if (d[breaked][nr][nc] == 0) {
                if (wall[nr][nc] == 0) {
                    d[breaked][nr][nc] = d[breaked][r][c] + 1;
                    q.push(point(nr,nc,breaked));
                }
                else {
                    if (breaked == 0) {
                        d[1][nr][nc] = d[breaked][r][c] + 1;
                        q.push(point(nr,nc,1));
                    }
                }
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c; cin >> c;
            (c == '1') ? wall[i][j] = 1 : wall[i][j] = 0;
        }
    }
    bfs();
}

