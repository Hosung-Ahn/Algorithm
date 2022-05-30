#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
# define MAX 50
int R,C,T, rr;
int board[MAX][MAX] = {0,};
int dust_board[MAX][MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

int diffuse(int r, int c) {
    int x = board[r][c] / 5;
    int ret = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!in_range(nr,nc) || board[nr][nc] == -1) continue;

        dust_board[nr][nc] += x;
        ret++;
    }
    return ret;
}

void board_diffuse() {
    for (int i = 0; i < MAX; i++)
        memset(dust_board[i], 0, sizeof(int)*MAX);
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] <= 0) continue;

            board[r][c] -= diffuse(r,c) * (board[r][c]/5);
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            board[r][c] += dust_board[r][c];
        }
    }
}

void air_cleaner_up(int r) {
    int last = 0, cur = 0;

    for (int c = 1; c < C; c++) {
        cur = board[r][c];
        board[r][c] = last;
        last = cur;
    }
    for (int nr = r-1; nr >= 0; nr--) {
        cur = board[nr][C-1];
        board[nr][C-1] = last;
        last = cur;
    }
    for (int c = C-2; c >= 0; c--){
        cur = board[0][c];
        board[0][c] = last;
        last = cur;
    }
    for (int nr = 1; nr < r; nr++) {
        cur = board[nr][0];
        board[nr][0] = last;
        last = cur;
    }
}

void air_cleaner_down(int r) {
    int last = 0, cur = 0;
    for (int c = 1; c < C; c++) {
        cur = board[r][c];
        board[r][c] = last;
        last = cur;
    }
    for (int nr = r+1; nr < R; nr++) {
        cur = board[nr][C-1];
        board[nr][C-1] = last;
        last = cur;
    }
    for (int c = C-2; c >= 0; c--){
        cur = board[R-1][c];
        board[R-1][c] = last;
        last = cur;
    }
    for (int nr = R-2; nr > r; nr--) {
        cur = board[nr][0];
        board[nr][0] = last;
        last = cur;
    }
}

void one_day() {
    board_diffuse();
    air_cleaner_up(rr-1);
    air_cleaner_down(rr);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> R >> C >> T;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
            if (board[r][c] == -1) rr = r;
        }
    }

    while(T--) {
        one_day();
    }

    int result = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == -1) continue; 
            result += board[r][c];
        }
    }

    cout << result;
}