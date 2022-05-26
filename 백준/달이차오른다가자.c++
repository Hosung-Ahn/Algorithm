#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 50

struct Node {
    int r,c,key,cnt;
    Node(int r, int c, int key, int cnt) : r(r), c(c), key(key), cnt(cnt) {}
};
int N,M;
vector<string> board;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
vector<vector<vector<int>>> visited(MAX, vector<vector<int>>(MAX, vector<int>()));

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

bool is_door(char c) {
    return c >= 'A' && c <= 'F';
}

bool is_key(char c) {
    return c >= 'a' && c <= 'f';
}

bool is_visited(int r, int c, int key) {
    for (int x : visited[r][c]) {
        if (x == key) return true;
    }
    return false;
}

void bfs(int sr, int sc) {
    queue<Node> q;
    q.push(Node(sr,sc,0,0));
    visited[sr][sc].push_back(0);

    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int c_key = q.front().key;
        int c_cnt = q.front().cnt;
        q.pop();
        if (board[cr][cc] == '1') {
            cout << c_cnt;
            return;
        }

        // cout << cr << " " << cc << " " << c_key << " " << c_cnt << endl;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == '#' || is_visited(nr,nc,c_key)) continue;

            if (is_door(board[nr][nc])) {
                if (c_key & (1 << (board[nr][nc] - 65))) {
                    visited[nr][nc].push_back(c_key);
                    q.push(Node(nr,nc,c_key,c_cnt+1));
                }
            }
            else if (is_key(board[nr][nc])) {
                int n_key = c_key | (1 << (board[nr][nc] - 97) );
                visited[nr][nc].push_back(n_key);
                q.push(Node(nr,nc,n_key,c_cnt+1));
            }
            else {
                visited[nr][nc].push_back(c_key);
                q.push(Node(nr,nc,c_key,c_cnt+1));
            }
        }
    }
    cout << -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s; 
        board.push_back(s);
    }

    int sr,sc;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == '0') {
                sr = r;
                sc = c;
                break;
            }
        }
    }

    bfs(sr,sc);
}