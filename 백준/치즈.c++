# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 100
int board[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if ( !in_range(nr,nc) || visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            if (board[nr][nc] == 1) {
                board[nr][nc] = 0;
                continue;
            }
            q.push({nr,nc});

        }
    }
} 

int count_cheeze() {
    int cnt = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == 1) cnt++;
        }
    }
    return cnt;
}

bool all_melt() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == 1) return false;
        }
    }
    return true;
}

void clear() {
    for (int i = 0; i < MAX; i++)
        memset(visited[i], 0, sizeof(bool)*MAX);
}

void print_result() {
    int count_time = 0;
    while (1) { 
        clear();
        int cheeze = count_cheeze();
        bfs(0,0);
        count_time++;
        if (all_melt()) {
            cout << count_time << "\n" << cheeze;
            break;
        }
    }

}

int main() {
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            scanf("%d", &board[r][c]);
        }
    }

    print_result();

}