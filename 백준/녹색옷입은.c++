# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 125
# define INF 987654321

int board[MAX][MAX];
int cost[MAX][MAX];
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void bfs() {
    cost[0][0] = board[0][0];
    queue<pair<int,int>> q;
    q.push({0,0});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if (!in_range(nr,nc) || cost[nr][nc] <= board[nr][nc] + cost[cr][cc])
                continue;
            cost[nr][nc] = board[nr][nc] + cost[cr][cc];
            q.push({nr,nc});
        }
    }
}

int main() {
    int idx = 1;
    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &board[i][j]);
                cost[i][j] = INF;
            }
        }

        bfs();
        printf("Problem %d: %d\n", idx++, cost[N-1][N-1]);
    }

}