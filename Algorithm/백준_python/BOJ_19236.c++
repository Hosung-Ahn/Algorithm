#include<iostream>
#include<vector>
using namespace std;
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,-1,-1,-1,0,1,1,1};
int total_ans = 0;

struct Fish {
    int r,c,d;
    bool died;
    Fish(int r=0, int c=0, int d=0) : r(r), c(c), d(d) {
        died = false;
    }
};

struct Shark {
    int r,c,d;
    Shark(int r, int c, int d) : r(r), c(c), d(d) {}
};

vector<Fish> fishArr(16);
vector<vector<int>> board(4, vector<int>(4, 0));

bool in_range(int r, int c) {
    if(r<0 || r>=4 || c<0 || c>=4) return false;
    return true;
}

void swap(vector<vector<int>> &board, vector<Fish> &fishArr,
                 int cr, int cc, int nr, int nc) {
    int ci = board[cr][cc];
    int ni = board[nr][nc];

    board[cr][cc] = ni;
    board[nr][nc] = ci;

    fishArr[ci].r = nr; 
    fishArr[ci].c = nc;
    fishArr[ni].r = cr;
    fishArr[ni].c = cc;
}

void fish_move(vector<Fish> &fishArr, vector<vector<int>> &board) {
    for(int i=0;i<16;i++) if (!fishArr[i].died) {
        int cr = fishArr[i].r;
        int cc = fishArr[i].c;
        for (int d=0;d<8;d++) {
            int nd = (fishArr[i].d + d) % 8;
            int nr = cr + dr[nd];
            int nc = cc + dc[nd];

            if (!in_range(nr, nc) || board[nr][nc] == 16) continue;
            fishArr[i].d = nd;
            swap(board, fishArr, cr,cc,nr,nc);
            break;
        }
    }
}

void dfs(Shark s, vector<Fish> fishArr, vector<vector<int>> board, int ans) {
    total_ans = max(total_ans, ans);
    // cout << ans << endl;
    fish_move(fishArr, board);
    int sr = s.r;
    int sc = s.c;
    int sd = s.d;

    board[sr][sc] = -1;
    for(int i=1;i<=3;i++){
        int nr = sr + dr[sd]*i;
        int nc = sc + dc[sd]*i;

        // cout << ans << " " <<  nr << " " << nc << " " << dr[s.d] << " " << dr[s.d] << endl;

        if (!in_range(nr,nc)) continue;

        
        // cout << nr << " " << nc << " " << board[nr][nc] << endl;
        if (board[nr][nc] >= 0 && board[nr][nc] <= 15) {
            int fi = board[nr][nc];
            board[nr][nc] = 16;
            fishArr[fi].died = true;
            s.d = fishArr[fi].d;
            s.r = nr;
            s.c = nc;
            dfs(s, fishArr, board, ans+fi+1);
            board[nr][nc] = fi;
            fishArr[fi].died = false;
            s.d = sd;
            s.r = sr;
            s.c = sc;
        }
    }
}

int main() {
    for(int r=0;r<4;r++) for(int c=0;c<4;c++) {
        int n,d; cin >> n >> d;
        fishArr[n-1] = Fish(r,c,d-1);
        board[r][c] = n-1;
    }

    int ans = board[0][0]+1;
    int sd = fishArr[board[0][0]].d;
    fishArr[board[0][0]].died = true;
    board[0][0] = 16;
    dfs(Shark(0,0,sd), fishArr, board, ans);
    cout << total_ans;
}