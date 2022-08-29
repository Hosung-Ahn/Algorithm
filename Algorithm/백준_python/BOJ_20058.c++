#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int board[64][64] = {0,};
int Qs[1000] = {0,};
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int N,Q; 

void rotate_one_line(int r, int c, int d) {
    queue<int> q;
    for(int i=0;i<d-1;i++) {
        q.push(board[r+d-1-i][c]);
    }
    for(int i=0;i<d-1;i++) {
        q.push(board[r][c+i]);
    }
    for(int i=0;i<d-1;i++) {
        q.push(board[r+i][c+d-1]);
    }
    for(int i=0;i<d-1;i++) {
        q.push(board[r+d-1][c+d-1-i]);
    }

    for(int i=0;i<d-1;i++) {
        board[r][c+i] = q.front();
        q.pop();
    }
    for(int i=0;i<d-1;i++) {
        board[r+i][c+d-1] = q.front();
        q.pop();
    }
    for(int i=0;i<d-1;i++) {
        board[r+d-1][c+d-1-i] = q.front();
        q.pop();
    }
    for(int i=0;i<d-1;i++) {
        board[r+d-1-i][c] = q.front();
        q.pop();
    }
}

void rotate_one_grid(int r, int c, int q) {
    for(int d=0;d<q/2;d++) {
        rotate_one_line(r+d,c+d,q-2*d);
    }
}

void rotate_total(int q) {
    for(int i=0;i<N/q;i++) for(int j=0;j<N/q;j++) {
        int r = i*q;
        int c = j*q;
        rotate_one_grid(r,c,q);
    }
}

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}

bool is_melt(int r, int c) {
    int cnt = 0;
    for(int i=0;i<4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!in_range(nr, nc) || board[nr][nc] == 0) continue;
        cnt++;
    }
    return cnt < 3;
}

void melt() {
    bool melted[64][64] = {0,};
    for(int r=0;r<N;r++) for(int c=0;c<N;c++)
    if (board[r][c] > 0 && is_melt(r,c)) {
        melted[r][c] = true;
    }

    for(int r=0;r<N;r++) for(int c=0;c<N;c++)
    if(melted[r][c]) {
        board[r][c]--;
    }
}

int bfs(int r, int c, bool visited[64][64]) {
    int ret = 1;
    visited[r][c] = true;
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc] == 0) continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
            ret++;
        }
    }
    return ret;
}

int largest_mass() {
    int ret = 0;
    bool visited[64][64] = {0,};
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) 
    if(!visited[r][c] && board[r][c] > 0){
        ret = max(ret, bfs(r,c,visited));
    }
    return ret;
}

void solve() {
    for(int i=0;i<Q;i++) {
        rotate_total(Qs[i]);
        melt();
    }
    int total = 0;
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        total += board[r][c];
    }
    cout << total << "\n" << largest_mass();
}

int main() {
    cin >> N >> Q;
    N = pow(2,N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        cin >> board[i][j];
    }
    for(int i=0;i<Q;i++) {
        int q; cin >> q;
        Qs[i] = (int)pow(2,q);
    }
    solve();
}