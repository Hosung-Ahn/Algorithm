#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dr[] = {0,-1,-1,0,1,1,1,0,-1};
int dc[] = {0,0,1,1,1,0,-1,-1,-1};

vector<string> boards[10];

vector<string> next_board(vector<string> board) {
    board.pop_back();
    board.insert(board.begin(), "........");
    return board;
}

struct Point {
    int r,c,d;
    Point(int r, int c, int d) : r(r), c(c), d(d) {}
};

bool in_range(int r, int c) {
    if (r<0 || r>=8 || c<0 || c>=8) return false;
    return true;
}

bool wall(int r, int c, int d) {
    if (boards[d][r][c] == '#' || boards[d+1][r][c] == '#')
        return true;
    return false;
}

void bfs() {
    Point start(7,0,0);
    queue<Point> q;
    q.push(start);

    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cd = q.front().d;
        q.pop();
        if (cr == 0 && cc == 7 || cd >= 8) {
            cout << 1;
            return;
        }

        for (int i=0;i<9;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];

            if (!in_range(nr,nc) || wall(nr,nc,cd)) continue;
            q.push(Point(nr,nc,cd+1));
        }
    }
    cout << 0;
}

int main() {
    for(int i=0;i<8;i++) {
        string s; cin >> s;
        boards[0].push_back(s);
    }
    for(int i=1;i<10;i++) {
        boards[i] = next_board(boards[i-1]);
    }

    bfs();
}