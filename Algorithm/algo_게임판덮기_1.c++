#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long 
int R,C; 
int ans = 0;
vector<string> board;

void togle(int r, int c, int k) {
    char g;
    if (board[r][c]=='.') g = '#';
    else g = '.';

    board[r][c] = g;

    if(k==0) {
        board[r][c+1] = g; 
        board[r+1][c+1] = g;
    }
    else if(k==1) { 
        board[r+1][c] = g;
        board[r+1][c-1] = g;
    }
    else if(k==2) {
        board[r+1][c+1] = g;
        board[r+1][c] = g;
    }
    else if(k==3) {
        board[r][c+1] = g;
        board[r+1][c] = g;
    }
}

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

bool is_color(int r, int c, int k) {
    if(k==0) {
        if (in_range(r,c+1) && board[r][c+1] == '.' &&
            in_range(r+1,c+1) && board[r+1][c+1] == '.') return true;
        return false;
    }
    else if(k==1) {
        if (in_range(r+1,c) && board[r+1][c] == '.' && 
            in_range(r+1,c-1) && board[r+1][c-1] == '.') return true;
        return false;
    }
    else if(k==2) {
        if (in_range(r+1,c) && board[r+1][c] == '.' && 
            in_range(r+1,c+1) && board[r+1][c+1] == '.') return true;
        return false;
    }
    else if(k==3) {
        if (in_range(r,c+1) && board[r][c+1] == '.' &&
            in_range(r+1,c) && board[r+1][c] == '.') return true;
        return false;
    }
}

void find_next(int &nr, int &nc) {
    int idx = nr*C + nc;
    for(int i=idx;i<R*C;i++) {
        int r = i / C, c = i % C;
        if (board[r][c] == '.') {
            nr = r; 
            nc = c;
            return;
        }
    }
}

void brute(int r, int c) {
    int nr = r, nc = c;
    
    find_next(nr,nc);

    if (nr == r && nc == c && board[r][c] == '#') {
        ans++;
        return;
    }

    for(int k=0;k<4;k++) {
        if (is_color(nr,nc,k)) {
            togle(nr,nc,k);
            brute(nr,nc);
            togle(nr,nc,k);
        }
    }
}

void solve() {
    cin >> R >> C;
    board.clear();
    ans = 0;
    for(int i=0;i<R;i++) {
        string s; cin >> s; 
        board.push_back(s);
    }
    brute(0,0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}