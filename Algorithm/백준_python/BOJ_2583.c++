#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100
int R,C,K;
bool board[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};


bool in_range(int r, int c) {
    if(r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

void fill(int r1, int c1, int r2, int c2) {
    for(int r=r1;r<r2;r++) for(int c=c1;c<c2;c++) {
        board[r][c] = true;
    }
}

int bfs(int r, int c) {
    queue<pair<int,int>> q;
    visited[r][c] = true;
    q.push({r,c});

    int ret = 0;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        ret++;

        for(int i=0;i<4;i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
    return ret;
}

void solve() {
    int ans = 0;
    vector<int> arr;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) 
    if(!board[r][c] && !visited[r][c]) {
        ans++;
        arr.push_back(bfs(r,c));
    }

    sort(arr.begin(), arr.end());

    cout << ans << endl;
    for(int x : arr) {
        cout << x << " "; 
    }
}

int main() {
    cin >> R >> C >> K;
    for(int i=0;i<K;i++) {
        int r1,c1,r2,c2;
        cin >> c1 >> r1 >> c2 >> r2;
        fill(r1,c1,r2,c2);
    }
    solve();
}