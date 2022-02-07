# include <iostream>
# include <string.h>
# include <vector>
# include <queue>
using namespace std;

# define MAX 100

int board[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc] && board[nr][nc] != 1) 
                continue;
            if (board[nr][nc] == 1) {
                visited[nr][nc]++;
                continue;
            }
            
            visited[nr][nc] = 1;
            q.push({nr,nc});
        }
    }
}

void melt() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] > 1) board[i][j] = 0;
        }
    }
}

void clear_visit() {
    for (int i = 0; i < MAX; i++)
        memset(visited[i], 0, sizeof(int)*MAX);
}

bool all_melted() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    int cnt = 0;
    while(!all_melted()) {
        cnt++;
        clear_visit();
        bfs();
        melt();
    }

    cout << cnt;


}

