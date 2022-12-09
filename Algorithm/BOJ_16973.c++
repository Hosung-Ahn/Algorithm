#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000
bool board[MAX][MAX] = {0,};
int R,C,H,W,sr,sc,fr,fc;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool in_range(int r, int c) {
    if(r<0 || r+H>R || c<0 || c+W>C) return false;
    return true;
}

bool is_wall(int r, int c, int d) {
    if (d==0) {
        for(int nc=c;nc<c+W;nc++) if(board[r-1][nc]) return true;
        return false;
    }
    else if (d==2) {
        for(int nc=c;nc<c+W;nc++) if(board[r+H][nc]) return true;
        return false;
    }
    else if (d==1) {
        for(int nr=r;nr<r+H;nr++) if(board[nr][c+W]) return true;
        return false;
    }
    else {
        for(int nr=r;nr<r+H;nr++) if(board[nr][c-1]) return true;
        return false;
    }
}

void bfs() {
    int visited[MAX][MAX];
    memset(visited, -1, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({sr,sc});
    visited[sr][sc] = 0;
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop(); 
        if (cr == fr && cc == fc) {
            cout << visited[cr][cc];
            return;
        }

        for(int d=0;d<4;d++) {
            int nr = cr+dr[d];
            int nc = cc+dc[d];
            if (!in_range(nr,nc) || is_wall(cr,cc,d) 
                || visited[nr][nc]>=0) continue;
            visited[nr][nc] = visited[cr][cc]+1;
            q.push({nr,nc});
        }
    }
    cout << -1;
}

void solve() {
    for(int r=sr;r<sr+H;r++) for(int c=sc;c<sc+W;c++) if(board[r][c]){
        cout << -1;
        return;
    }
    bfs();
}

int main() {
    cin >> R >> C;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) cin >> board[r][c];
    cin >> H >> W >> sr >> sc >> fr >> fc;
    sr--;
    sc--;
    fr--;
    fc--;
    solve();
}