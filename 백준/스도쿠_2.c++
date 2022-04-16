# include <iostream>
using namespace std;

int board[9][9] = {0,};

bool is_ok(int r, int c, int n) {
    for (int i = 0; i < 9; i++) {
        if (i == r) continue;
        if (board[i][c] == n) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (i == c) continue;
        if (board[r][i] == n) return false;
    }

    int cr = (r/3)*3;
    int cc = (c/3)*3;
    for (int i = cr; i < cr+3; i++) {
        for (int j = cc; j < cc+3; j++) {
            if (i == r && j == c) continue;
            if (board[i][j] == n) return false;
        }
    }

    return true;
}

bool solve(int i) {
    if (i == 81) return true;

    for (int cur = i; cur < 81; cur++) {
        int cr = cur/9;
        int cc = cur%9;

        if (board[cr][cc] == 0) {
            for (int n = 1; n <= 9; n++) {
                if (is_ok(cr,cc,n)) {
                    board[cr][cc] = n;
                    if (solve(cur+1)) return true;
                    board[cr][cc] = 0;
                }
            }
            return false;
        }
    }

    return true;
}

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            scanf("%d", &board[i][j]);

    solve(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}