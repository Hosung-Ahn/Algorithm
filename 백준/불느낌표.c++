# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <cstring>
using namespace std;
# define MAX 1000

int R,C; 
vector<string> board;
queue<pair<int,int>> fire_q;
int Fire[MAX][MAX];
int Cnt[MAX][MAX];
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void count_fire() {
    while(!fire_q.empty()) {
        int cr = fire_q.front().first;
        int cc = fire_q.front().second;
        fire_q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == '#' || Fire[nr][nc] >= 0) continue;
            Fire[nr][nc] = Fire[cr][cc] + 1; 
            fire_q.push({nr,nc});
        }
    }
}

void solution(int r, int c) {
    Cnt[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc)) {
                cout << Cnt[cr][cc] + 1;
                return;
            }

            if (board[nr][nc] == '#' 
            || (Fire[nr][nc] <= Cnt[cr][cc]+1 && Fire[nr][nc] != -1)
            || Cnt[nr][nc] >= 0) continue;

            Cnt[nr][nc] = Cnt[cr][cc] + 1;
            q.push({nr,nc});
        } 
    }

    cout << "IMPOSSIBLE";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int sr,sc;

    for (int i = 0; i < MAX; i++) {
        memset(Fire[i], -1, sizeof(int)*MAX);
        memset(Cnt[i], -1, sizeof(int)*MAX);
    }

    for (int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if (board[r][c] == 'F') {
                fire_q.push({r,c});
                Fire[r][c] = 0;
            }
            if (board[r][c] == 'J') {
                sr = r;
                sc = c;
            }
        }
    }

    count_fire();
    solution(sr,sc);
}