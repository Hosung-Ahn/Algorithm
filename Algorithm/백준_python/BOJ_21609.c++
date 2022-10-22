#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 20

int N,M;
int board[MAX][MAX];
bool visited[MAX][MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int ans = 0;

bool in_range(int r, int c) {
    if (r<0||r>=N||c<0||c>=N) return false;
    return true;
}

bool can_go(int r, int c, int check) {
    if (board[r][c] < 0) return false;
    else if (board[r][c] == 0) return true;
    return board[r][c] == check;
}

int count_block(int r, int c, int &rainbow) {
    int check = board[r][c];
    bool bfs_visited[MAX][MAX] = {0,};
    queue<pair<int,int>> q;
    q.push({r,c}); 
    bfs_visited[r][c] = true;

    int ret = 0;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (board[cr][cc] > 0) visited[cr][cc] = true;
        ret++;
        if (board[cr][cc] == 0) rainbow++;

        for(int i=0;i<4;i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || bfs_visited[nr][nc] 
                || !can_go(nr,nc,check)) continue;
            bfs_visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }

    return ret;
}

void delete_block(int r, int c) {
    int check = board[r][c];
    bool bfs_visited[MAX][MAX] = {0,};
    queue<pair<int,int>> q;
    q.push({r,c}); 
    bfs_visited[r][c] = true;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        board[cr][cc] = -2;

        for(int i=0;i<4;i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || bfs_visited[nr][nc] 
                || !can_go(nr,nc,check)) continue;
            bfs_visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
}

void fall_one(int r, int c) {
    while(in_range(r+1, c) && board[r+1][c] == -2) {
        int tmp = board[r+1][c];
        board[r+1][c] = board[r][c];
        board[r][c] = tmp;
        r++;
    }
}

void fall() {
    for(int r=N-1;r>=0;r--) for(int c=0;c<N;c++) {
        if (board[r][c] >= 0) fall_one(r,c);
    }
}

void rotate() {
    int next_board[MAX][MAX];
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        next_board[r][c] = board[c][N-1-r];
    }
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) {
        board[r][c] = next_board[r][c];
    }
}

bool one_time() {
    int xr,xc;
    int max_cnt = 0;
    int max_rainbow = 0;
    memset(visited, 0, sizeof(visited));
    
    for(int r=0;r<N;r++) for (int c=0;c<N;c++) {
        if(visited[r][c] || board[r][c] <= 0) continue;
        int tmp_rainbow = 0;
        int tmp = count_block(r,c,tmp_rainbow);
        if (max_cnt < tmp || (max_cnt==tmp && tmp_rainbow >= max_rainbow)) {
            xr = r;
            xc = c;
            max_cnt = tmp;
            max_rainbow = tmp_rainbow;
        }
    }

    if (max_cnt < 2) return false;

    ans += max_cnt * max_cnt;
    

    delete_block(xr,xc);
    fall();
    rotate();
    fall();

    return true; 
}

int main() {
    cin >> N >> M;
    for(int r=0;r<N;r++) for (int c=0;c<N;c++) cin >> board[r][c];
    while (one_time()) {}
    cout << ans;
}