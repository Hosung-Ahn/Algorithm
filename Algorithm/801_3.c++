#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000

int board[MAX][MAX];
int R,C;
bool ck = false;

bool in_range(int r, int c) {
    if (r >= R || c >= C) return false;
    return true;
}

void dfs(int r, int c, int cur) {
    if (r == R-1 && c == C-1) {
        if (cur == 0) ck = true;
        return;
    }
    if (!in_range(r,c) || cur >= max(R,C) || cur <= -max(R,C) ) return;
    dfs(r+1,c,cur + board[r+1][c]);
    dfs(r,c+1,cur + board[r][c+1]);    
}

void solve() {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c= 0; c < C; c++) {
            cin >> board[r][c];
        }
    }
    ck = false;
    dfs(0,0,board[0][0]);

    cout << (ck == true ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}