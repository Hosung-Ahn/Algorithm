#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>
using namespace std;
#define MAX 1000
vector<string> board;
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int SET[MAX][MAX] = {0,};

int go_d(char c) {
    if (c == 'U') return 0;
    else if (c == 'R') return 1;
    else if (c == 'D') return 2;
    else return 3;
}

int get_parent(int a) {
    int r = a/C;
    int c = a%C;
    if (SET[r][c] == a) return a;
    return SET[r][c] = get_parent(SET[r][c]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a < b) SET[b/C][b%C] = SET[a/C][a%C];
    else SET[a/C][a%C] = SET[b/C][b%C];
}

bool is_SET(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a == b;
}

void dfs(int r, int c) {
    int idx = r*C+c;
    int d = go_d(board[r][c]);
    int nr = r+dr[d];
    int nc = c+dc[d];
    int next_idx = nr*C+nc;

    if (is_SET(idx, next_idx)) return;
    union_node(idx, next_idx);
    dfs(nr,nc);
}

void solve() {
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        dfs(r,c);
    }

    set<int> s;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        s.insert(SET[r][c]);
    }
    cout << s.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    
    int idx = 0;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        SET[r][c] = idx++;
    }

    solve();
}