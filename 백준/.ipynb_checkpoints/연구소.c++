# include <iostream>
# include <queue>
# include <vector>

using namespace std;

vector< vector<int> > board;
queue<pair<int,int>> virus;
int R,C;

int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int result = 0;

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

int secure_area(queue<pair<int,int>> virus, vector<vector<int>> map) {
    while (!virus.empty()) {
        int r = virus.front().first;
        int c = virus.front().second;
        virus.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (in_range(nr,nc) && map[nr][nc] == 0) {
                map[nr][nc] = 2; 
                virus.push({nr,nc});
            }

        }
    }

    int cnt = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == 0) cnt++;
        }
    }
    return cnt;
}

void find_result(int idx, int cnt) {
    if (cnt == 3) {
        int secure = secure_area(virus, board);
        result = max(result, secure);
        return;
    }
    for (int i = idx; i < R*C; i++) {
        int r = i / C, c = i % C;
        if (board[r][c] == 0) {
            board[r][c] = 1;
            find_result(i, cnt + 1);
            board[r][c] = 0;
        }
    }
}

int main() {
    board.assign(8, vector<int>(8,0));
    cin >> R >> C;

    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            scanf("%d", &board[r][c]);
            if (board[r][c] == 2) virus.push({r,c});
        }
    }

    find_result(0,0);

    cout << result << endl; 

    
}