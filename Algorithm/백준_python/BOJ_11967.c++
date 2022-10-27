#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100

vector<pair<int,int>> rights[MAX][MAX];
bool turn_on[MAX][MAX] = {0,};
bool moved[MAX][MAX] = {0,};
int N, ans = 0;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}

bool bfs() {
    bool ret = false;
    bool visited[MAX][MAX] = {0,};
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (!moved[cr][cc]) {
            moved[cr][cc] = true;
            for (auto right : rights[cr][cc]) if (!turn_on[right.first][right.second]) {
                turn_on[right.first][right.second] = true;
                ans++;
                ret = true;
            }
        }

        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || !turn_on[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
    return ret;
}

void solve() {
    turn_on[0][0] = true;
    ans++;
    while(bfs()) {}
    cout << ans;
}

int main() {
    int M; cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        rights[a-1][b-1].push_back({c-1,d-1});
    }

    solve();
}