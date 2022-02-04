# include <iostream>
# include <string>
# include <vector>
# include <cstring> 
using namespace std;

vector<string> board;
int R,C; 

bool visited[10000][500] = {0,};
int dr[] = {-1,0,1};
int dc[] = {1,1,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

bool connect_pipe(int r, int c) {
    if (c == C-1) return true;

    for (int i = 0; i < 3; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (!in_range(nr,nc) || board[nr][nc] == 'x' || visited[nr][nc]) continue;

        visited[nr][nc] = true;
        
        if (connect_pipe(nr,nc)) {
            board[r][c] = 'x';
            return true;
        }
    }
    return false;
}



void print_result() {
    int result = 0;
    for (int r = 0; r < R; r++) {
        if (connect_pipe(r,0)) result++;
    }
    cout << result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        string s; cin >> s;
        board.push_back(s);
    }

    print_result();
}