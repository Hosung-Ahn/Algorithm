#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> board;
int R,C;
char load[] = {'|','-','+','1','2','3','4'};
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

bool check(int r, int c) {
    for(int i=0;i<7;i++) {
        if (board[r][c] == load[i]) return true;
    }
    return false;
}

bool dfs(int r, int c, bool change, int d) {
    if (!in_range(r,c)) return false;
    if (board[r][c] == 'Z') return true;
    if (board[r][c] == '.') {
        if (change) return false;
        for(int i=0;i<7;i++) {
            board[r][c] = load[i];
            if (dfs(r,c, true, d)) {
                cout << r+1 << " " << c+1 << " " << load[i] << endl;
                return true;
            }
        }
    }
    if (board[r][c] == '|') {
        if (d == 1 || d == 3) return false;
        return dfs(r+dr[d], c+dc[d], change, d);
    }
    if (board[r][c] == '-') {
        if (d == 0 || d == 2) return false;
        return dfs(r+dr[d], c+dc[d], change, d);
    }
    if (board[r][c] == '+') {
        return dfs(r+dr[d], c+dc[d], change, d);
    }
    if (board[r][c] == '1') {
        if (d == 1 || d == 2) return false;
        if (d == 0) return dfs(r,c+1,change,1);
        if (d == 3) return dfs(r+1,c,change,2);
    }
    if (board[r][c] == '2') {
        if (d == 0 || d == 1) return false;
        if (d == 2) return dfs(r,c+1,change,1);
        if (d == 3) return dfs(r-1,c,change,0);
    }
    if (board[r][c] == '3') {
        if (d == 0 || d == 3) return false;
        if (d == 1) return dfs(r-1,c,change,0);
        if (d == 2) return dfs(r,c-1,change,3);
    }
    if (board[r][c] == '4') {
        if (d == 2 || d == 3) return false;
        if (d == 1) return dfs(r+1,c,change,2);
        if (d == 0) return dfs(r,c-1,change,3);
    }

}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) if (board[r][c]=='M') {
        for(int d=0;d<4;d++) {
            int nr = r+dr[d];
            int nc = c+dc[d];
            if (!in_range(nr,nc) || !check(nr,nc)) continue;
            dfs(nr,nc,false,d);
            break;
        }
    }
}