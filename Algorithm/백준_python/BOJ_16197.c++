#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

vector<string> board;
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if(r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

struct Node {
    int r1,c1,r2,c2, k;
    Node(int r1, int c1, int r2, int c2, int k) : r1(r1), c1(c1), r2(r2), c2(c2), k(k) {}
};

void bfs(Node start) {
    queue<Node> q;
    q.push(start);
    while(!q.empty()) {
        int cr1 = q.front().r1;
        int cc1 = q.front().c1;
        int cr2 = q.front().r2;
        int cc2 = q.front().c2;
        int ck = q.front().k;
        q.pop();

        if (ck>=10) continue;

        for(int i=0;i<4;i++) {
            int nr1 = cr1+dr[i];
            int nc1 = cc1+dc[i];
            int nr2 = cr2+dr[i];
            int nc2 = cc2+dc[i];

            int out_cnt = 0;
            if(!in_range(nr1,nc1)) out_cnt++;
            if(!in_range(nr2,nc2)) out_cnt++;

            if (out_cnt==2) continue;
            else if (out_cnt==1) {
                cout << ck+1;
                return;
            }
            else {
                if (board[nr1][nc1] == '#') {
                    nr1 = cr1;
                    nc1 = cc1;
                }
                if (board[nr2][nc2] == '#') {
                    nr2 = cr2;
                    nc2 = cc2;
                }
                q.push(Node(nr1,nc1,nr2,nc2,ck+1));
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    int r1,c1,r2,c2;
    bool ck = false;

    for(int r=0;r<R;r++)for(int c=0;c<C;c++) {
        if (board[r][c] == 'o') {
            if (ck) {
                r2 = r;
                c2 = c;
            }
            else {
                r1 = r;
                c1 = c;
                ck = true;
            }
        }
    }
    bfs(Node(r1,c1,r2,c2,0));
}