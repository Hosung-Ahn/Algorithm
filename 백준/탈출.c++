# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <cstdio>
# include <string.h>
using namespace std;

# define MAX 50

vector<string> board;
queue<pair<int,int>> water;
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int dist[MAX][MAX];

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void water_bfs() {
    int size = water.size();
    for (int k = 0; k < size; k++) {
        int cr = water.front().first;
        int cc = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == '*' 
                || board[nr][nc] == 'X' || board[nr][nc] == 'D')
                continue;
            
            board[nr][nc] = '*';
            water.push({nr,nc});
        }
    }
}

void D_bfs(int r, int c ) {
    dist[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    int cnt = -1;
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (dist[cr][cc] != cnt) {
            water_bfs();
            cnt = dist[cr][cc];
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || board[nr][nc] == '*' 
                || board[nr][nc] == 'X' || dist[nr][nc] != -1)
                continue;
            
            dist[nr][nc] = dist[cr][cc] + 1;
            if (board[nr][nc] == 'D') return;
            q.push({nr,nc});
        }
    }
    
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int sr,sc, fr,fc;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == '*')
                water.push({r,c});
            if (board[r][c] == 'S') {
                sr = r;
                sc = c;
            }
            if (board[r][c] == 'D') {
                fr = r;
                fc = c;
            }

        }
    }

    for (int i = 0; i < MAX; i++) 
        memset(dist[i], -1, sizeof(int)*MAX);

    D_bfs(sr,sc);

    if (dist[fr][fc] == -1) cout << "KAKTUS";
    else cout << dist[fr][fc];
    
}