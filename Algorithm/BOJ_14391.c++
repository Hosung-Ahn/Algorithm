#include <iostream>
#include <vector>
#include <string> 
using namespace std;
vector<string> board;
int R,C;
bool bin[4][4] = {0,};
int ans = 0;

int cal_tmp() {
    int ret = 0;
    bool visited[4][4] = {0,};
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) if(!visited[r][c]) {
        int x = 0;
        if (bin[r][c]) {
            int nr = r;
            while(nr<R && bin[nr][c]) {
                x *= 10;
                x += board[nr][c]-'0';
                visited[nr][c] = true;
                nr++;
            }
        }
        else {
            int nc = c;
            while(nc<C && !bin[r][nc]) { 
                x *= 10;
                x += board[r][nc]-'0';
                visited[r][nc] = true;
                nc++;
            }
        }
        ret += x;
    }
    return ret;
}

void dfs(int idx) {
    if (idx == R*C) {
        ans = max(ans, cal_tmp());
        return;
    }
    int r = idx/C;
    int c = idx%C;
    dfs(idx+1);
    bin[r][c] = 1;
    dfs(idx+1);
    bin[r][c] = 0;
}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string s; cin >> s; 
        board.push_back(s);
    }
    dfs(0);
    cout << ans;
}