# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 100
int N;
int board[MAX][MAX];
int island[MAX][MAX] = {0,};
int total_cnt[MAX][MAX];

int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool next_point(int &nr, int &nc) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == 1) {
                nr = r;
                nc = c;
                return true;
            }
        }
    }
    return false;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void bfs_island(int r, int c, int n) {
    island[r][c] = n;
    board[r][c] = 0;
    
    queue<pair<int,int>> q;
    q.push({r,c});
    while (!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || board[nr][nc] == 0) continue;
            board[nr][nc] = 0;
            island[nr][nc] = n;
            q.push({nr,nc});
        }
    }
}

void island_numbering() {
    int r,c;
    int n = 1;
    while (next_point(r,c)) {
        bfs_island(r,c,n++);
    }
}

void find_result() {
    int result = 987654321;

    queue<pair<int,int>> q;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (island[r][c] != 0) {
                q.push({r,c});
                total_cnt[r][c] = 0;
            }
        }
    }

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || island[nr][nc] == island[cr][cc]) continue;

            if (island[nr][nc] != 0) {
                result = min(result, total_cnt[cr][cc] + total_cnt[nr][nc] );
                break;
            }

            island[nr][nc] = island[cr][cc];
            total_cnt[nr][nc] = total_cnt[cr][cc] + 1;
            q.push({nr,nc});
        }
    }
    cout << result;
}



int main() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++){
            scanf("%d", &board[r][c]);
        }
    }
    island_numbering();

    for (int i = 0; i < MAX; i++)
        memset(total_cnt[i], -1, sizeof(int)*MAX);

    find_result();
}