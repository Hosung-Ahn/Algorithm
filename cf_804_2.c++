#include<iostream>
using namespace std;
#define MAX 50

void solve() {
    int board[MAX][MAX] = {0,};
    int R,C; cin >> R >> C;

    for(int r=0;r<R/2;r++) for(int c=0;c<C/2;c++) {
        if ((r+c)%2) {
            board[2*r][2*c] = 0;
            board[2*r][2*c+1] = 1;
            board[2*r+1][2*c] = 1;
            board[2*r+1][2*c+1] = 0;
        }
        else {
            board[2*r][2*c] = 1;
            board[2*r][2*c+1] = 0;
            board[2*r+1][2*c] = 0;
            board[2*r+1][2*c+1] = 1;
        }
    }
    
    for (int r=0;r<R;r++) {
        for (int c=0;c<C;c++) {
            cout << board[r][c] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
