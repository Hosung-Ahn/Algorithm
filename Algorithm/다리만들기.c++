# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 100
int N;
int board[MAX][MAX];
int island[MAX][MAX] = {0,};
int total_cnt[MAX][MAX] = {0,};

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
    queue<pair<int,int>> q;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (island[r][c] != 0) {
                q.push({r,c});
            }
        }
    }
    int cnt = 1; 

    
}

int one_bfs(queue<pair<int,int>> &q, int cnt) {
    queue<pair<int,int>> next_q;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || island[nr][nc] == island[cr][cc]) continue;

            if (island[nr][nc] != 0) {
                if (total_cnt[nr][nc] == cnt) return 1;
                else return 0;
            }
            total_cnt[nr][nc] = cnt;
            island[nr][nc] = island[cr][cc];
            next_q
        }

        return -1;
    }
}



int main() {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++){
            scanf("%d", &board[r][c]);
        }
    }
    cout << endl;

    island_numbering();
}