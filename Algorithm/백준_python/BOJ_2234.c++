#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int R,C;
int board[50][50] = {0,};
int room[50][50] = {0,};
int areas[2501] = {0,};
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}



int bfs(int r, int c, int num) {
    int area = 1;
    queue<pair<int,int>> q;
    q.push({r,c});
    room[r][c] = num;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        int k = board[cr][cc];
        int i = 0;

        while(k || i < 4) {
            if (k%2==0) {
                int nr = cr+dr[i];
                int nc = cc+dc[i];
                if (in_range(nr,nc) && room[nr][nc] == 0) {
                    room[nr][nc] = num;
                    area++;
                    q.push({nr,nc});
                }
            }
            k/=2;
            i++;
        }
    }

    return area;
}

int two_sum() {
    int ret = 0;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        for(int i=0;i<4;i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!in_range(nr,nc) || room[r][c] == room[nr][nc]) continue;
            ret = max(ret, areas[room[r][c]]+areas[room[nr][nc]]);
        }
    }
    return ret;
}

void solve() {
    int num = 1;
    int max_area = 0;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) if(room[r][c] == 0) {
        areas[num] = bfs(r,c, num);
        max_area = max(max_area, areas[num]);
        num++;
    }

    cout << num-1 << endl;
    cout << max_area << endl;
    cout << two_sum() << endl;
}

int main() {
    cin >> C >> R;
    for(int r=0;r<R;r++) for(int c=0;c<C;c++) {
        cin >> board[r][c];
    }

    solve();
}