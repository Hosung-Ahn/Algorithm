# include <iostream>
# include <algorithm>
# include <queue>
# include <vector>
using namespace std;
# define MAX 1001

struct point {
    int r,c;
    bool breaked;
    point(int r, int c, bool breaked = false) : r(r), c(c), breaked(breaked) {}
};

int N,M;
int d[MAX][MAX] = {0,};
int wall[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {0,};

int dr[] = {-1, 0,1,0};
int dc[] = {0 ,-1,0,1};

bool in_range(int r, int c){
    if (r >= 1 && r <= N && c >= 1 && c <= M) return true;
    return false;
}

void bfs(int r, int c) {
    queue<point> q; 
    d[r][c] = 1;
    visited[r][c] = true;
    q.push(point(r,c));

    while (!q.empty()) {
        point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            point next(current.r + dr[i], current.c + dc[i], current.breaked);
            if (in_range(next.r, next.c)) {
                if (!visited[next.r][next.c]) {
                    if (!wall[next.r][next.c]) {
                        d[next.r][next.c] = d[current.r][current.c] + 1;
                        visited[next.r][next.c] = true;
                        q.push(next);
                    }
                    else {
                        if (!current.breaked) {
                            d[next.r][next.c] = d[current.r][current.c] + 1;
                            visited[next.r][next.c] = true;
                            next.breaked = true;
                            q.push(next);
                        }
                    }
                }
                else { 
                    if (!current.breaked) q.push(next);
                }
            }
        }
    }
}


int main() {
    cin >> N >> M;
    char c;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> c;
            if (c == '1') wall[i][j] = 1;
            else wall[i][j] = 0;
        }
    }
    bfs(1,1);
    int min_path = d[N][M];
    if (min_path == 0) cout << -1;
    else cout << min_path;
}