# include <iostream>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 200
# define INF 987654321

int visited[31][MAX][MAX];
int board[MAX][MAX] = {0,};
int K,N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

int dr_horse[] = {-2,-1,1,2,2,1,-1,-2};
int dc_horse[] = {1,2,2,1,-1,-2,-2,-1};

class Point{
public:
    int r,c,k;
    Point(int k, int r, int c) : k(k), r(r), c(c) { }
};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs() {
    queue<Point> q;
    q.push(Point(0,0,0));
    visited[0][0][0] = 0;

    while (!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int ck = q.front().k;
        q.pop();

        if (cr == N-1 && cc == M-1) {
            cout << visited[ck][cr][cc];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || visited[ck][nr][nc] != -1
                || board[nr][nc] == 1) continue;
            visited[ck][nr][nc] = visited[ck][cr][cc] + 1;
            q.push(Point(ck, nr, nc));
        }

        if (ck < K) {
            int nk = ck + 1;
            for (int i = 0; i < 8; i++) {
                int nr = cr + dr_horse[i];
                int nc = cc + dc_horse[i];

                if (!in_range(nr,nc) || visited[nk][nr][nc] != -1
                    || board[nr][nc] == 1) continue;
                visited[nk][nr][nc] = visited[ck][cr][cc] + 1;
                q.push(Point(nk,nr,nc));
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> K >> M >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            scanf("%d", &board[r][c]);
        }
    }

    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < MAX; j++) {
            memset(visited[i][j], -1, sizeof(int)*MAX);
        }
    }

    bfs();
    
}   