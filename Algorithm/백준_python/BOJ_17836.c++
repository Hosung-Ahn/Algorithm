#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 100
#define INF 987654321

int N,M,T;
int board[MAX][MAX] = {0,};
int cnt[MAX][MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    cnt[0][0] = 0;

    int gram = -1;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (board[cr][cc] == 2) {
            gram = N-1-cr + M-1-cc + cnt[cr][cc];
        }

        for (int i=0;i<4;i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || cnt[nr][nc] > 0 || board[nr][nc] == 1) continue;

            q.push({nr,nc});
            cnt[nr][nc] = cnt[cr][cc] + 1;
        }
    }
    if (gram != -1) {
        if (cnt[N-1][M-1] == 0) cnt[N-1][M-1] = gram;
        else cnt[N-1][M-1] = min(cnt[N-1][M-1], gram);
    }

    if (cnt[N-1][M-1] == 0 || cnt[N-1][M-1] > T) {
        cout << "Fail";
        return;
    }
    cout << cnt[N-1][M-1];
}

int main() {
    cin >> N >> M >> T;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
        cin >> board[i][j];
    }
    bfs();
}