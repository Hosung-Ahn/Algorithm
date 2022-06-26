#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 30
#define INF 1987654321

vector<pair<int,int>> edges[MAX*MAX];
int board[MAX][MAX] = {0,};
int R,C;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void bellman_ford() {
    int cost[MAX*MAX];
    for (int i = 0; i < R*C; i++) cost[i] = INF;
    cost[0] = 0;
    for (int i = 0; i < R*C; i++) {
        for (int cur = 0; cur < R*C-1; cur++) {
            for (pair<int,int> next : edges[cur]) { 
                int next_node = next.first;
                int next_cost = next.second;
                if (cost[cur] != INF && cost[next_node] > cost[cur] + next_cost) {
                    cost[next_node] = cost[cur] + next_cost;
                    if (i == R*C-1) {
                        cout << "Never\n";
                        return;
                    }
                }
            }
        }
    }
    if (cost[R*C-1] == INF) cout << "Impossible\n";
    else cout << cost[R*C-1] << "\n";
}

void clear() {
    for (int i = 0; i < MAX; i++) 
        memset(board[i], 0, sizeof(int)*MAX);
    for (int i = 0; i < MAX*MAX; i++) {
        edges[i].clear();
    }
}

bool solve() {
    cin >> C >> R;
    if (C == 0 && R == 0) return false;
    int G; cin >> G;
    for (int i = 0; i < G; i++) {
        int c,r; cin >> c >> r;
        board[r][c] = -1;
    }
    for (int i = 0; i < R*C-1; i++) {
        int r = i / C, c = i % C;
        if (board[r][c] == -1) continue;

        for (int j = 0; j < 4; j++) {
            int nr = r + dr[j];
            int nc = c + dc[j];
            if (!in_range(nr,nc) || board[nr][nc] == -1) continue;
            edges[i].push_back({nr*C+nc,1});
        }
    }

    int E; cin >> E;
    for (int i = 0; i < E; i++) {
        int c1,r1, c2,r2,d; cin >> c1 >> r1 >> c2 >> r2 >> d;
        edges[r1*C+c1].clear();
        edges[r1*C+c1].push_back({r2*C+c2, d});
    }
    bellman_ford();
    clear();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(solve());
}