#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 100
int board[MAX][MAX] = {0,};
bool sink[MAX][MAX] = {0,};
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false; 
    return true;
}

void bfs(int r, int c) { 
    queue<pair<int,int>> q;
    sink[r][c] = true;
    q.push({r,c});

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr, nc) || sink[nr][nc]) continue;

            sink[nr][nc] = true;
            q.push({nr,nc});
        }
    }
}

int cal(int h) {
    for (int i = 0; i < MAX; i++) {
        memset(sink[i], false, sizeof(bool)*MAX);
    }
    // memset(sink, false, sizeof(sink));

    // for (int r = 0; r < N; r++) {
    //     for (int c = 0; c < N; c++) {
    //         cout << sink[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (board[i][j] <= h) sink[i][j] = true;
    }
    
    int ret = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (sink[r][c]) continue;
            ret++;
            bfs(r,c);
        }
    }
    return ret;
}


int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    // cout << cal(4) << endl;

    for (int h = 0; h <= 100; h++) {
        ans = max(ans, cal(h));
    }
    cout << ans;
}