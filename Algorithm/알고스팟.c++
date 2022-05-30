# include <iostream> 
# include <vector>
# include <queue>
# include <string>
using namespace std;

# define MAX 100
# define INF 100000

vector<string> board;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int cnt[MAX][MAX];
int N,M;

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs() {
    cnt[0][0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        int cur_cnt = cnt[cr][cc];
        q.pop();


        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc)) continue;

            int next_cnt;
            if (board[nr][nc] == '1') next_cnt = cur_cnt + 1;
            else next_cnt = cur_cnt;

            if (cnt[nr][nc] <= next_cnt) continue;

            cnt[nr][nc] = next_cnt;
            q.push({nr,nc});
        }

    }
}

int main() {
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < MAX; j++) 
            cnt[i][j] = INF;

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    
    bfs();

    cout << cnt[N-1][M-1];
}