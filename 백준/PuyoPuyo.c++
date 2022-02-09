# include <iostream>
# include <queue>
# include <vector>
# include <string>
using namespace std;

vector<string> board;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= 12 || c < 0 || c >= 6) return false;
    return true;
}

bool is_combo(int r, int c, vector<vector<bool>> &visited) {
    int cnt = 1;
    char color = board[r][c];
    queue<pair<int,int>> q;
    visited[r][c] = true;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first; 
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc] 
                || board[nr][nc] != color) continue;
            
            visited[nr][nc] = true;
            q.push({nr,nc});
            cnt++;
        }
    }
    if (cnt >= 4) return true;
    return false;
}

void explosion(int r, int c) {
    char color = board[r][c];
    board[r][c] = '.';
    bool visited[12][6] = {0,};
    queue<pair<int,int>> q;
    visited[r][c] = true;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc]
                || board[nr][nc] != color) continue;

            visited[nr][nc] = true; 
            board[nr][nc] = '.';
            q.push({nr,nc});
        }
    }
}

bool one_time() {
    vector<vector<bool>> visited(12, vector<bool>(6,false));
    bool ret = false;

    for (int r = 0; r < 12; r++) {
        for (int c = 0; c < 6; c++) {
            if (board[r][c] == '.' || visited[r][c]) continue;

            if (is_combo(r,c,visited)) {
                explosion(r,c);
                ret = true;
            }
        }
    }
    return ret;
}

void move_down(int r, int c) {
    int i = 1;
    int nr;
    while (1) {
        nr = r + i;
        if (nr == 12 || board[nr][c] != '.') break;
        i++;
    }
    char tmp = board[nr-1][c];
    board[nr-1][c] = board[r][c];
    board[r][c] = tmp;
}

void board_move_down() {
    for (int r = 11; r >= 0; r--) {
        for (int c = 0; c < 6; c++) {
            if (board[r][c] != '.') move_down(r,c);
        }
    }
}

void print_result() {
    int cnt = 0;
    while (one_time()) {
        cnt++;
        board_move_down();
    }
    cout << cnt;
}

int main() {
    for (int i = 0; i < 12; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    print_result();

}

