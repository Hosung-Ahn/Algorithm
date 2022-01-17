# include <iostream> 
# include <vector>
# include <queue>
# include <string.h>
# include <cstdio>
using namespace std;

# define MAX 50

int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int dist[MAX][MAX];
int R,C;
vector<string> board;

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void clear() {
    for (int i = 0; i < MAX; i++)
        memset(dist[i], -1, sizeof(int)*MAX);
}

int bfs(int r, int c) {
    clear();

    dist[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    int result = 0;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || board[nr][nc] == 'W' || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[cr][cc] + 1;
            q.push({nr,nc});
            if (dist[nr][nc] > result)
                result = dist[nr][nc];
            
        }
    }

    return result;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int result = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'W') continue;
            int max_dist = bfs(r,c);
            if (max_dist > result)
                result = max_dist;
        }
    }

    cout << result;
    

    


}