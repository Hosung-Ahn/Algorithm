# include <iostream>
# include <vector>
# include <string>
# include <math.h>
# include <map>
# include <queue>
using namespace std;
# define INF 987654321;

vector<string> board;
map<int,int> dp;
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

int to_bit(const vector<string> &board) {
    int result = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == '*')
                result += pow(2, 5*r + c);
        }
    }
    return result;
}

vector<string> to_board(int bit) {
    int i = 0;
    vector<string> ret(5,".....");
    while (bit != 0) {
        if (bit%2==1) {
            ret[i/5][i%5] = '*';
        }
        bit/=2;
        i++;
    }
    return ret;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
    return true;
}

bool is_connected(const vector<string> &board) {
    queue<pair<int,int>> q;
    bool visited[5][5] = {0,};
    for (int r = 0; r < 5; r++){
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == '*') {
                q.push({r,c});
                visited[r][c] = 1;
                break;
            }
        }
    }

    int cnt = 1;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc] != '*') {
                continue;
            }

            visited[nr][nc] = 1;
            q.push({nr,nc});
            cnt++;
        }
    }

    return cnt==N;
}

int find_dp(int bit) {
    vector<string> cur_board = to_board(bit);

    if (is_connected(cur_board)) return 0;
    if (dp[bit] != 0) return dp[bit];
    int result = INF;

    int i = 0;
    while (bit != 0) {
        if (bit%2==1) {
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    if (cur_board[r][c] == '*') {
                        
                    }
                }
            }
        }
        bit/=2;
        i++;
    }


}

int main() {
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    
}