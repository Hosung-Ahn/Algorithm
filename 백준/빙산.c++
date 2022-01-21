# include <iostream>
# include <vector>
# include <cstdio>
# include <queue>
using namespace std;

vector<vector<int>> board;
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) { 
    if (r < 0 || r >= R || c < 0 || c >= C ) return false;
    return true;
}

void bfs(int r, int c, vector<vector<int>> &board) {
    board[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == 0) continue;
            board[nr][nc] = 0;
            q.push({nr,nc});
        }
    }
}

bool next_start(int &nr, int &nc, vector<vector<int>> &board) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] != 0) {
                nr = r;
                nc = c;
                return true;
            }
        }
    }
    return false;
}

void melt() {
    vector<vector<int>> copy_board = board;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (copy_board[r][c] == 0) continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (copy_board[nr][nc] == 0) {
                    if (board[r][c] == 0) continue;
                    board[r][c]--;
                }
            }
        }
    }
}

int is_separated() {
    vector<vector<int>> copy_board = board;
    int r,c;
    int cnt = 0;
    while (next_start(r,c,copy_board)) { 
        bfs(r,c,copy_board);
        cnt ++;
        if (cnt >= 2) return 2;
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        vector<int> row;
        for (int c = 0; c < C; c++) {
            int x; cin >> x;
            row.push_back(x);
        }
        board.push_back(row);
    }

    int result = 0;
    while (1) {
        int cnt = is_separated();

        if (cnt == 0) {
            cout << 0;
            break;
        }

        if (cnt == 2) {
            cout << result;
            break;
        }

        melt();
        
        // cout << endl;
        // for (int r = 0; r < R; r++) {
        //     for (int c = 0; c < C; c++) {
        //         cout << board[r][c] << " ";
        //     }
        //     cout << endl;
        // }
        result++;
    }
}

