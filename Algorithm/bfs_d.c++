#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
#define INF 987654321

struct Node {
    int r,c,d;
    Node(int r, int c, int d) : r(r), c(c), d(d) {}
};
int visited[MAX][MAX][4];
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int board[MAX][MAX];

bool in_range(int r, int c) {
    if (r<0 || r>=MAX || c<0 || c>=MAX) return false;
    return true;
}

void bfs(int r, int c) {
    queue<Node> q;
    for(int d=0;d<4;d++) {
        visited[r][c][d] = 0;
        q.push(Node(r,c,d));
    }
    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cd = q.front().d;
        q.pop();

        for(int nd=0;nd<4;nd++) {
            int nr = cr+dr[nd];
            int nc = cc+dc[nd];
            int next_cnt = visited[cr][cc][cd] + (cd == nd ? 1 : 2);
            if (!in_range(nr,nc) || board[nr][nc] == 1 ||
                visited[nr][nc][nd] <= next_cnt) continue;
            visited[nr][nc][nd] = next_cnt;
            q.push(Node(nr,nc,nd));
        }
    }
}