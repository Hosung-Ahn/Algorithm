# include <iostream>
# include <vector>
# include <queue>
# include <string>
# include <map>
using namespace std;

# define END "123456789"

char board[3][3];
map<string,int> visited;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

string board_to_string() {
    string ret;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.push_back(board[i][j]);
        }
    }
    return ret;
}

void string_to_board(const string &str) {
    for (int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        board[r][c] = str[i];
    }
}

void find_rc(int &r, int &c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '9') {
                r = i;
                c = j;
                return;
            }
        }
    }
}

bool in_range(int r, int c) {
    if (r < 0 || r >= 3 || c < 0 || c >= 3) return false;
    return true;
}

void swap_board(int r, int c, int nr, int nc) {
    char tmp = board[r][c];
    board[r][c] = board[nr][nc];
    board[nr][nc] = tmp;
    return;
}


void bfs(string start) {
    queue<string> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == END) {
            cout << visited[cur] -1;
            return;
        }

        string_to_board(cur);
        int cr,cc;
        find_rc(cr,cc);

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc)) continue;
            swap_board(cr,cc, nr,nc);
            string next = board_to_string();
            if (visited[next]) {
                swap_board(cr,cc, nr,nc);
                continue;
            }
            q.push(next);
            swap_board(cr,cc, nr,nc);
            visited[next] = visited[cur] + 1;
        }
    }
    cout << -1;
}

int main() {
    string start;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c; cin >> c;
            if (c == '0') start.push_back('9');
            else start.push_back(c);
        }
    }

    bfs(start);

}

