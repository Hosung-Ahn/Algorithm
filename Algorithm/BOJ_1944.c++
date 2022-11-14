#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 50

struct Node {
    int s,e,d;
    Node(int s, int e, int d) : s(s), e(e), d(d) {}
    bool operator<(const Node &other) const {
        return d < other.d;
    }
};
int N,M;
vector<string> board_origin;
int board[MAX][MAX];
int idx = 2;
vector<Node> arr;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int set[260];

void find_board() {
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        if(board_origin[r][c] == '1') board[r][c] = -1;
        else if(board_origin[r][c] == '0') board[r][c] = 0;
        else if(board_origin[r][c] == 'S') board[r][c] = 1;
        else board[r][c] = idx++;
    }
}

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}

void bfs(int r, int c) {
    int s = board[r][c];
    int visited[MAX][MAX];
    memset(visited, -1, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = 0;
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        int e = board[cr][cc];
        if (e > 0 && s != e) {
            arr.push_back(Node(s,e,visited[cr][cc]));
        }

        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || visited[nr][nc]!=-1 || board[nr][nc] == -1) continue;
            visited[nr][nc] = visited[cr][cc]+1;
            q.push({nr,nc});
        }
    }
}

void find_arr() {
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        if (board[r][c] > 0) {
            bfs(r,c);
        }
    }
}

int get_parent(int cur) {
    if (cur == set[cur]) return cur;
    return set[cur] = get_parent(set[cur]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a < b) set[b] = a;
    else set[a] = b;
}

bool is_set(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a==b;
}

void MST() {
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<idx;i++) set[i] = i;
    sort(arr.begin(), arr.end());
    for(Node node : arr) {
        if (!is_set(node.s, node.e)) {
            union_node(node.s, node.e);
            ans += node.d;
            cnt++;
        }
    }
    cout << (cnt==idx-2 ? ans : -1);
}

void solve() {
    find_board();
    find_arr();
    MST();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        string s; cin >> s; 
        board_origin.push_back(s);
    }
    solve();
}
