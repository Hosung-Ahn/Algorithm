# include <iostream>
# include <vector>
# include <queue>
# include <math.h>
# include <string.h>
using namespace std;

# define MAX 50

int board[MAX][MAX];
int union_board[MAX][MAX] = {0, };
int total_p[MAX*MAX+1] = {0,};
int total_cnt[MAX*MAX+1] = {0,};

int N, L, R;
int union_cnt = 0;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool all_unioned(int &idx) {
    while (idx < N*N) {
        int r = idx / N, c = idx % N;
        if (union_board[r][c] == 0 ) {
            union_cnt++;
            total_p[union_cnt] += board[r][c];
            total_cnt[union_cnt]++;
            return false;
        }
        idx++;
    }
    
    return true;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

bool is_linked(int r, int c, int nr, int nc) {
    int p_d = abs(board[r][c] - board[nr][nc]);
    if (p_d >= L && p_d <= R) return true;
    return false; 
}

void set_union(int r, int c) {
    union_board[r][c] = union_cnt;
    queue<pair<int,int>> bfs;
    bfs.push({r,c});

    while (!bfs.empty()) {
        int cr = bfs.front().first;
        int cc = bfs.front().second;
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (in_range(nr,nc) && is_linked(cr,cc, nr,nc) && union_board[nr][nc] == 0) {
                union_board[nr][nc] = union_cnt;
                bfs.push({nr,nc});
                total_p[union_cnt] += board[nr][nc];
                total_cnt[union_cnt]++;
            }
        }
    }
}

void one_day() {
    int idx = 0;
    while (!all_unioned(idx)) {
        int r = idx / N, c = idx % N;
        set_union(r,c);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = total_p[union_board[i][j]] / total_cnt[union_board[i][j]];
        }
    }
}

void clear() { 
    memset(total_p, 0, sizeof(int)*(MAX*MAX+1));
    memset(total_cnt, 0, sizeof(int)*(MAX*MAX+1));
    for (int i = 0; i < MAX; i++) 
        memset(union_board[i], 0, sizeof(int)*MAX);
    union_cnt = 0;
}

int total_day(){
    int result = 0;
    while(1) {
        one_day();
        if (union_cnt >= N*N) return result;
        result++;
        clear();
    }
    return result;
}

int main() {
    cin >> N >> L >> R; 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);

    cout << total_day() << endl;
    
}