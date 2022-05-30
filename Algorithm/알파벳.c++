# include <iostream> 
# include <string>
# include <vector>
# include <cstdio>

using namespace std;

# define MAX 20
vector<string> board;
int R,C;
int result = 0;
vector<char> stacked;
bool visited[MAX][MAX] = {0, };

int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

bool is_include(char c) {
    for (int i = 0; i < stacked.size(); i++) {
        if(stacked[i] == c) return true;
    }
    return false;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void dfs(int r, int c) {
    if (!in_range(r,c) || visited[r][c]) return;
    char cur = board[r][c];
    if (is_include(cur)) return;

    stacked.push_back(cur);
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        dfs(nr,nc);
    }

    if (stacked.size() > result) result = stacked.size();
    stacked.pop_back();
    visited[r][c] = false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    dfs(0,0);

    cout << result;

}