# include <iostream>
# include <cstring>
using namespace std;
# define MAX 10

bool board[MAX][MAX] = {0,};
int N, total_cnt = 0;
int seted[MAX][MAX] = {0,};
int dr[] = {-1,1,-1,1};
int dc[] = {-1,-1,1,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void set(int r, int c, bool deset = false) {
    int k = 1;
    if (deset) k = -1;
    seted[r][c] += k;

    for (int i = 0; i < 4; i++) {
        int nr = r, nc = c;
        while(1) {
            nr += dr[i];
            nc += dc[i];
            if (!in_range(nr,nc)) break;
            seted[nr][nc] += k;
        }
    }
}

int find_dfs(int idx) {
    // cout << idx << endl;
    for (int i = idx; i < N*N; i+=2) {
        int r = i / N;
        int c = i % N;
        if (N%2 == 0 && c == N-1) i--;
        if (N%2 == 0 && c == N-2) i++;

        if (!board[r][c] || seted[r][c]) continue;

        set(r,c);
        int set_cnt = 1 + find_dfs(i+2);
        set(r,c,true);
        int deset_cnt = find_dfs(i+2);
        return max(set_cnt, deset_cnt);
    }
    return 0;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << find_dfs(0) + find_dfs(1);

    
}