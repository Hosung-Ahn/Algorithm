# include <iostream>
# include <queue>
# include <cstdio>
using namespace std;

# define MAX 1001

int N, M;
int d[MAX][MAX];
bool wall[MAX][MAX];
bool visited[MAX][MAX] = {0,};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0,-1, 0, 1};

struct point {
    int r,c;
    bool breaked;
    point(int r, int c, bool b) : r(r), c(c), breaked(b) { }
};

bool in_range(int r, int c) {
    if (r >= 1 && r <= N && c >= 1 && c <= M) return true;
    return false;
}

void bfs(){
    d[1][1] = 1;
    visited[1][1] = true;
    queue<point> q;
    q.push(point(1,1,false));

    while(!q.empty()){
        point cur = q.front();
        if (cur.r == N && cur.c == M) return; 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_r = cur.r + dr[i];
            int next_c = cur.c + dc[i];
            bool breaked = cur.breaked; 
            if (in_range(next_r, next_c)) { 
                if(!visited[next_r][next_c]) {
                    if (!wall[next_r][next_c]) {
                        d[next_r][next_c] = d[cur.r][cur.c] + 1;
                        visited[next_r][next_c] = true;
                        q.push(point(next_r,next_c, breaked));
                    }
                    else {
                        if (!breaked) {
                            d[next_r][next_c] = d[cur.r][cur.c] + 1;
                            visited[next_r][next_c] = true;
                            q.push(point(next_r,next_c, true));
                        }
                    }
                }
                // 벽을 뚫고 온 애가 먼저 지나갔는데 
                // 벽을 안뚫고 온 애가 나중에 올 때 하지만 마지막에는
                // 결정적인 벽을 안뚫고 온 애가 뚫어서 더 빨리 지나갈 때
                else {
                    if(cur.breaked == false && !wall[next_r][next_c]) {
                        d[next_r][next_c] = d[cur.r][cur.c] + 1;
                        q.push(point(next_r, next_c, breaked));
                    }
                }
            }

        }
    }
}

int main() { 
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++){
            char c; cin >> c;
            (c == '1') ? wall[i][j] = 1 : wall[i][j] = 0;
        }
    }

    bfs();

    int min_path = d[N][M];
    if (min_path == 0) cout << -1;
    else cout << min_path;

}