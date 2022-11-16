#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000

struct Node {
    int r,c,cnt;
    Node(int r, int c, int cnt) : r(r), c(c), cnt(cnt) {}
};

vector<string> board;
vector<pair<int,int>> qs[10];
int visited[MAX][MAX];
int s[10];
int ans[MAX][MAX];
int R,C,P;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) { 
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

void bfs(int p) {
    queue<Node> q;
    for(auto pair : qs[p]) {
        int r = pair.first;
        int c = pair.second;
        q.push(Node(r,c,0));
        visited[r][c] = 0;
    }

    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int ccnt = q.front().cnt;
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            int ncnt = ccnt+1;
            if (!in_range(nr,nc) || board[nr][nc] != '.') continue;
            int cnt_visited = (ncnt-1)/s[p]+1;
            if (visited[nr][nc] != -1 && visited[nr][nc] <= cnt_visited) continue;
            visited[nr][nc] = cnt_visited;
            ans[nr][nc] = p;
            q.push(Node(nr,nc,ncnt));
        }
    }
}

void solve() {
    memset(visited, -1, sizeof(visited));
    memset(ans, -1, sizeof(ans));
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        if (board[r][c] == '.' || board[r][c] == '#') continue;
        int p = board[r][c] - '1';
        qs[p].push_back({r,c});
        ans[r][c] = p;
    }

    for(int p=0;p<P;p++) bfs(p);

    int result[10] = {0,};
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) if(ans[r][c] != -1) {
        result[ans[r][c]]++;
    }

    for(int p=0;p<P;p++) cout << result[p] << " ";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> R >> C >> P;
    for(int i=0;i<P;i++) cin >> s[i];
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    solve();
}