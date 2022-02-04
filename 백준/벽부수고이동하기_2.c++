# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 1000

int board[MAX][MAX];
int total_cnt[11][MAX][MAX] = {0,};
int N,M,K;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

class Point {
public:
    int k, r, c;
    Point(int k, int r, int c) : k(k), r(r), c(c) { }
};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs() {
    total_cnt[0][0][0] = 1;
    queue<Point> q;
    q.push(Point(0,0,0));

    while (!q.empty()) {
        int ck = q.front().k;
        int cr = q.front().r;
        int cc = q.front().c;
        q.pop();

        if (cr == N-1 && cc == M-1) {
            cout << total_cnt[ck][cr][cc];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc)) continue;

            if (board[nr][nc] == 0) {
                if (total_cnt[ck][nr][nc] != 0) continue;

                total_cnt[ck][nr][nc] = total_cnt[ck][cr][cc] + 1;
                q.push(Point(ck,nr,nc));
            }
            else {
                if (ck < K) {
                    if (total_cnt[ck+1][nr][nc] != 0) continue;

                    total_cnt[ck+1][nr][nc] = total_cnt[ck][cr][cc] + 1;
                    q.push(Point(ck+1,nr,nc));
                }
            }
            
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> M >> K;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            scanf("%1d", &board[r][c]);
        }
    }

    bfs();

}


