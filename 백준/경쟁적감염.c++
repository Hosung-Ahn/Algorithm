#include <iostream> 
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 200

struct Node {
    int s,i,r,c;
    Node(int s, int i, int r, int c) : s(s), i(i), r(r), c(c) {}
};
int board[MAX][MAX] = {0,};
int cnt[MAX][MAX]; 
int N,K;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
} 

struct cmp {
    bool operator()(const Node &a, const Node &b) {
        if (a.s == b.s) return a.i > b.i;
        return a.s > b.s;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

void bfs() {
    while(!pq.empty()) {
        int cr = pq.top().r;
        int cc = pq.top().c;
        int ci = pq.top().i;
        int cs = pq.top().s;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if (!in_range(nr,nc) || board[nr][nc] != 0) continue;

            board[nr][nc] = ci;
            cnt[nr][nc] = cnt[cr][cc] + 1;
            pq.push(Node(cs+1, ci, nr, nc));
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < MAX; i++)
        memset(cnt[i], -1, sizeof(int)*MAX);

    cin >> N >> K;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
            if (board[r][c] != 0) {
                pq.push(Node(0,board[r][c], r, c));
                cnt[r][c] = 0;
            }
        }
    }
    int s,x,y; cin >> s >> x >> y;
    bfs();
    if (cnt[x-1][y-1] > s) cout << 0;
    else cout << board[x-1][y-1];
}