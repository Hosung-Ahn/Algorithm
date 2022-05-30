# include <iostream>
# include <vector>
# include <queue>
using namespace std;
# define MAX 10
# define INF 987654321

bool visited[MAX][MAX] = {0,};
bool board[MAX][MAX] = {0,};
int bridge[MAX][MAX] = {0,};
int N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int result = INF;


bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void visit_bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || !board[nr][nc] || visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr,nc});
        }

    }
}

bool find_next(int &idx, int &r, int &c) {
    for (; idx < N*M; idx++) {
        int nr = idx / M;
        int nc = idx % M;

        if (visited[nr][nc]) continue;
        visited[nr][nc] = true;

        if (board[nr][nc]) {
            visit_bfs(nr,nc);
            r = nr;
            c = nc;
            return true;
        }
    }
    return false;
}

bool can_bridged(int r, int c, int d) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    int cnt = 0;

    while(in_range(nr,nc)) {
        if (board[nr][nc]) {
            if (cnt >= 2) return true;
            return false;
        } 

        cnt++;
        nr += dr[d];
        nc += dc[d];
    }

    return false;
}

bool all_bridged() {
    bool visited_tmp[MAX][MAX];

    int r,c;
    for (int i = 0; i < N*M; i++) {
        int cr = i / M;
        int cc = i % M;
        if (board[cr][cc]) {
            r = cr;
            c = cc;
            break;
        }
    }

    queue<pair<int,int>> q;
    q.push({r,c});
    visited_tmp[r][c] = true; 

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        cout << cr << " " << cc << endl;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited_tmp[nr][nc] || !(board[nr][nc] || bridge[nr][nc])) continue;

            visited_tmp[nr][nc] = true;
            q.push({nr,nc});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] && !visited_tmp[i][j]) return false;
        }
    }
    return true;
}

int set_bridge(int r, int c, int d, bool deset = false) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    int cnt = 0;

    int k = 1;
    if (deset) k = -1;

    while(1) {
        if (board[nr][nc]) return cnt; 
        bridge[nr][nc] += k;
        nr += dr[d];
        nc += dc[d];
        cnt++;
    }

    return cnt;
}

void solution_dfs(int idx, int cnt) {
    int r,c;
    cout << idx << endl;
    if (find_next(idx,r,c)) {
        // cout << r << " " << c << " " << cnt << endl;
        bool visited_tmp[MAX][MAX] = {0,};
        queue<pair<int,int>> q;
        q.push({r,c});
        visited_tmp[r][c] = true;

        while (!q.empty()) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (!in_range(nr,nc) || visited_tmp[nr][nc]) continue;

                if (!board[nr][nc]) {
                    if (can_bridged(nr,nc,i)) {
                        int tmp = set_bridge(nr,nc,i);
                        solution_dfs(idx, cnt + tmp);
                        set_bridge(nr,nc,i,true);
                    }
                    else continue;
                }
                else {
                    visited_tmp[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        return;
    }

    if (all_bridged()) {
        result = min(result, cnt);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    solution_dfs(0,0);

    if (result == INF) cout << -1;
    else cout << result;
    
}