# include <iostream>
using namespace std;

# define MAX 100

int board[MAX][MAX] = {0,};
int R,C;

bool is_ok(int r, int c) {
    int x = board[r][c] + board[r+1][c] + board[r][c+1] + board[r+1][c+1];
    if (x == 3) return false;
    return true;
}

void solve() {
    for (int r = 0; r < R-1; r++) {
        for (int c = 0; c < C-1; c++) {
            if (!is_ok(r,c)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &R, &C);
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf("%1d", &board[r][c]);
            }
        }
        solve();
    }
}

