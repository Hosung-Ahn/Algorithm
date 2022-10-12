#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

vector<string> board;
string word;
int R,C,K;
int visited[100][100][80];
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

int dfs(int r, int c, int k) {
    if (board[r][c] != word[k]) return 0;
    if (k == word.size()-1) return 1;

    int &ret = visited[r][c][k];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=1;i<=K;i++) {
        for (int d=0;d<4;d++) {
            int nr = r + dr[d]*i;
            int nc = c + dc[d]*i;

            if (!in_range(nr,nc)) continue;
            ret += dfs(nr,nc,k+1);
        }
    }
    return ret;
}

int main() {
    cin >> R >> C >> K;
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    cin >> word;
    for(int i=0;i<100;i++) for(int j=0;j<100;j++) memset(visited[i][j], -1, sizeof(int)*80);
    
    int ans = 0;
    for (int r=0;r<R;r++) for(int c=0;c<C;c++) {
        ans += dfs(r,c,0);
    }
    cout << ans;
}