#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 10000

vector<string> board;
int num[20][20] = {0,};
int dist[11][11] = {0,};
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int R,C;

void clear() {
    board.clear();
    for(int i=0;i<20;i++) memset(num[i], 0, sizeof(int)*20);
}

bool in_range(int r, int c) {
    if(r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

void bfs(int r, int c) {
    int start = num[r][c];
    bool visited[20][20] = {0,};
    int d[20][20] = {0,};
    visited[r][c] = true;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first; 
        int cc = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr, nc) || board[nr][nc] == 'x' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            d[nr][nc] = d[cr][cc]+1;
            q.push({nr,nc});
        }
    }
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        if(num[r][c]) {
            int n = num[r][c];
            if (n == start) continue;
            int td;
            d[r][c] == 0 ? td = INF : td = d[r][c];
            dist[start][n] = td;
        }
    }    
}

void find_dist() {
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        if(num[r][c]) {
            bfs(r,c);
        }
    }
}

int cal_dist(const vector<int> &arr) {
    int ret=0;
    int s = 1;
    for(int e : arr) {
        ret += dist[s][e];
        s = e;
    }
    return ret;
}

bool solve() {
    clear();
    cin >> C >> R;
    if (C==0 && R==0) return false;
    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    int idx = 2;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        if(board[r][c] == '*') {
            num[r][c] = idx++;
        }
        else if(board[r][c] == 'o') {
            num[r][c] = 1;
        }
    }
    find_dist();

    vector<int> arr;
    for(int i=2;i<idx;i++) {
        arr.push_back(i);
    }
    int ans = 987654321;
    do {
        ans = min(ans, cal_dist(arr));
    } while(next_permutation(arr.begin(), arr.end()));
    ans >= INF ? cout << "-1\n" : cout << ans << "\n";
    return true;
}

int main() {
    while(solve()) {}
}