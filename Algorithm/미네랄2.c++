#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 101

int R,C;
vector<string> board;
vector<int> op;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
bool visited[MAX][MAX] = {0,};
bool on_air[MAX][MAX] = {0,};

void bar(int h, bool d) {
    h = R-h;
    if (d) {
        for(int i=0;i<C;i++) if(board[h][i]=='x') {
            board[h][i] = '.';
            return;
        }
    }
    else {
        for(int i=C-1;i>=0;i--) if(board[h][i]=='x') {
            board[h][i] = '.';
            return;
        }
    }
}

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

void bfs(int r, int c) {
    visited[r][c] = true;
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc]=='.') continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
}

int tmp_dist(int r, int c) {
    int ret = 0;
    for (int nr = r+1; nr < R; nr++) {
        if (on_air[nr][c]) return 1000;
        if (board[nr][c]=='x') break;
        ret++;
    }
    return ret;
}

int cal_dist(int r, int c) {
    for(int i=0;i<MAX;i++) memset(on_air[i],0,MAX*sizeof(bool));
    int dist = 1000;

    queue<pair<int,int>> q;
    q.push({r,c});
    on_air[r][c] = true;
    
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || on_air[nr][nc] || board[nr][nc]=='.') continue;
            on_air[nr][nc] = true;
            q.push({nr,nc});
        }
    }

    for(int cr=0;cr<R;cr++) for(int cc=0;cc<C;cc++) if (on_air[cr][cc]) {
        dist = min(dist, tmp_dist(cr,cc));
    }

    for(int cr=R-1;cr>=0;cr--) for(int cc=C-1;cc>=0;cc--) if(on_air[cr][cc]) {
        board[cr][cc]='.';
        board[cr+dist][cc]='x';
    }
}

void fall() {
    for(int i=0;i<MAX;i++) memset(visited[i],0,MAX*sizeof(bool));

    for(int c=0;c<C;c++) if(board[R-1][c]=='x' && !visited[R-1][c]) bfs(R-1,c);

    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        if (board[r][c]=='x' && !visited[r][c]) {
            cal_dist(r,c);
            return;
        }
    }
}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string s; cin>>s;
        board.push_back(s);
    }
    int N; cin >> N;
    op.resize(N);
    for(int i=0;i<N;i++) {
        cin>>op[i];
    }

    bool d = true;
    for(int h : op) {
        bar(h, d);
        fall();
        d = !d;
    }

    for (string s : board) {
        cout << s << "\n";
    }
}