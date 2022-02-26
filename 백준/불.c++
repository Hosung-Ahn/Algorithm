# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <string.h>
using namespace std;

# define MAX 1000

vector<string> board;
int fire_cnt[MAX][MAX];
int step_cnt[MAX][MAX];
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

bool in_fire(int r, int c, int cnt) {
    if (fire_cnt[r][c] == -1) return false;
    if (fire_cnt[r][c] <= cnt) return true;
    return false; 
}

void move_fire() {
    queue<pair<int,int>> q;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == '*') {
                q.push({r,c});
                fire_cnt[r][c] = 0;
            }
        }
    }

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) 
            || fire_cnt[nr][nc] != -1
            || board[nr][nc] == '#') 
                continue;

            fire_cnt[nr][nc] = fire_cnt[cr][cc] + 1;
            q.push({nr,nc});
        }
    }
}

void move_step() {
    queue<pair<int,int>> q;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == '@') {
                q.push({r,c});
                step_cnt[r][c] = 0;
            }
        }
    }

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop(); 

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!in_range(nr,nc)) {
                cout << step_cnt[cr][cc] + 1 << "\n";
                return;
            }

            if(step_cnt[nr][nc] != -1 
            || in_fire(nr,nc,step_cnt[cr][cc] + 1)
            || board[nr][nc] == '#') 
                continue;

            step_cnt[nr][nc] = step_cnt[cr][cc] + 1;
            q.push({nr,nc});
        }
    }

    cout << "IMPOSSIBLE\n";
}

void clear() {
    for (int i = 0; i < MAX; i++) {
        memset(fire_cnt[i], -1, sizeof(int)*MAX);
        memset(step_cnt[i], -1, sizeof(int)*MAX);
    }
    board.clear();
}

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        clear();
        cin >> C >> R;
        for (int i = 0; i < R; i++) {
            string s; cin >> s;
            board.push_back(s);
        }
        move_fire();
        move_step();
    }
}