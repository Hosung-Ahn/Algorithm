#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define MAX 50
vector<string> board;
int sr,sc,sa,er,ec,ea, N;
int visited[MAX][MAX][2];
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

struct Node {
    int r,c,a;
    Node(int r, int c, int a) : r(r), c(c), a(a) {}
};

void find_SE() {
    for(int c=0;c<N;c++) {
        for(int r=1;r<N-1;r++) {
            if(board[r-1][c]=='B' && board[r][c]=='B' && board[r+1][c]=='B') {
                sr = r;
                sc = c;
                sa = 0;
            }
            if(board[r-1][c]=='E' && board[r][c]=='E' && board[r+1][c]=='E') {
                er = r;
                ec = c;
                ea = 0;
            }
        }
    }
    for(int r=0;r<N;r++) {
        for(int c=1;c<N-1;c++) {
            if(board[r][c-1]=='B' && board[r][c]=='B' && board[r][c+1]=='B') {
                sr = r;
                sc = c;
                sa = 1;
            }
            if(board[r][c-1]=='E' && board[r][c]=='E' && board[r][c+1]=='E') {
                er = r;
                ec = c;
                ea = 1;
            }
        }
    }
}

bool in_range(int r, int c, int a) {
    if (a == 0) {
        if (r-1<0 || r+1>=N || c<0 || c>=N) return false;
        if (board[r-1][c] == '1' || board[r][c] == '1' || board[r+1][c] == '1') return false;
        return true;
    }
    else {
        if (c-1<0 || c+1 >= N || r<0 || r>=N) return false;
        if (board[r][c-1]=='1' || board[r][c]=='1' || board[r][c+1]=='1') return false;
        return true;
    }
}

bool in_rotate_range(int r, int c) {
    if (r-1<0 || r+1>=N || c-1<0 || c+1>= N) return false;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
        if (board[r-1+i][c-1+j] == '1') return false;
    }
    return true;
}

void bfs() {
    visited[sr][sc][sa] = 0;
    queue<Node> q;
    q.push(Node(sr,sc,sa));
    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int ca = q.front().a;
        q.pop();

        if (cr == er && cc == ec && ca == ea) {
            cout << visited[cr][cc][ca];
            return;
        }

        for(int i=0;i<4;i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc,ca) || visited[nr][nc][ca] >= 0) continue;
            visited[nr][nc][ca] = visited[cr][cc][ca]+1;
            q.push(Node(nr,nc,ca));
        }
        int na = (ca+1)%2;
        if (!in_rotate_range(cr,cc) || visited[cr][cc][na] >= 0) continue;
        visited[cr][cc][na] = visited[cr][cc][ca]+1;
        q.push(Node(cr,cc,na));
    }
    cout << 0;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) {
        visited[i][j][0] = -1;
        visited[i][j][1] = -1;
    }
    find_SE();
    bfs();
}