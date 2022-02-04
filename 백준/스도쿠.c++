# include <iostream>
using namespace std;

int board[9][9] = {0,};

bool is_ok(int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][c] == num) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == num) return false;
    }

    int box_r = r / 3 * 3;
    int box_c = c / 3 * 3;

    for (int i = box_r; i < box_r + 3; i++) {
        for (int j = box_c; j < box_c + 3; j++) {
            if (board[i][j] == num) return false;
        }
    }

    return true;
}

bool find_dp(int x) {
    if (x == 81) return true;

    for (int nx = x; nx < 81; nx++) {
        int nr = nx / 9;
        int nc = nx % 9;

        if (board[nr][nc] != 0) continue;

        for (int num = 1; num <= 9; num++) {
            if (is_ok(nr,nc,num)) {
                board[nr][nc] = num;
                if (find_dp(nx+1)) return true;
                else {
                    board[nr][nc] = 0;
                }
            }
        }
        return false;
    }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    find_dp(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }


}