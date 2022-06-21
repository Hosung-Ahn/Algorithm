#include<iostream>
using namespace std;
#define MAX 40

int board[MAX][MAX];

void solve() {
    int R,C; cin >> R  >> C;
    int max_num = -1000000000;
    int mr, mc;
    for (int r = 0; r < R; r++) {
        for (int c = 0;c < C; c++) {
            cin >> board[r][c];
            if (max_num < board[r][c]) {
                max_num = board[r][c];
                mr = r;
                mc = c;
            }
        }
    }
    int ar = max(mr+1, R-mr);
    int ac = max(mc+1, C-mc);
    cout << ar*ac << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}