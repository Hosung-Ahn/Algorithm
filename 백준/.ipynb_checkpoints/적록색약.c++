# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
# include <cstdio>

using namespace std;

# define MAX 100

char board[MAX][MAX];
int colored[MAX][MAX] = {0, };
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int result = 0;

bool all_colored(int &r, int &c) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (colored[i][j] == 0) {
                r = i;
                c = j;
                return false;
            }
        }
    }
    return true;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void set_color(int r, int c, bool color_weakness) {
    char color = board[r][c];
    queue<pair<int,int>> bfs;
    bfs.push({r,c});
    result++;
    colored[r][c] = result;

    while (!bfs.empty()) {
        int cr = bfs.front().first;
        int cc = bfs.front().second;
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (in_range(nr,nc) && colored[nr][nc] == 0) {
                if (color_weakness && (color == 'R' || color == 'G')) {
                    if (board[nr][nc] == 'B') continue;
                }
                else {
                    if (board[nr][nc] != color) continue;
                }
                colored[nr][nc] = result;
                bfs.push({nr,nc});
            }
        }
    }
}

void find_result(bool color_weakness = false) { 
    int r, c;
    while (!all_colored(r,c)) {
        set_color(r,c, color_weakness);
    }
}

void clear() {
    for (int i = 0; i < MAX; i++) 
        memset(colored[i], 0, sizeof(int)*MAX);
    result = 0; 
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            board[i][j] = c;
        }
    }
    
    find_result(false);
    int not_color_weakness_cnt = result;

    clear();
    find_result(true);
    int color_weakness_cnt = result;

    cout << not_color_weakness_cnt << " " << color_weakness_cnt;
            
}