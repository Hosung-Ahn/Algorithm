# include <iostream> 
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 20
int board[MAX][MAX] = {0,};
int dist[MAX][MAX];
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void bfs(int r, int c, int size) {
    dist[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || board[nr][nc] > size || dist[nr][nc] != -1) continue; 
            dist[nr][nc] = dist[cr][cc] + 1;
            q.push({nr,nc});
        }
    }
}

bool next_prey(int &nr, int &nc, int size) {
    int min_dist = 500;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (dist[r][c] == -1 || board[r][c] == 0) continue; 

            if (board[r][c] < size && dist[r][c] < min_dist) {
                min_dist = dist[r][c];
                nr = r;
                nc = c;
            }
        }
    }
    if (min_dist == 500) return false;
    return true;
}

int cal_time(int r, int c) {
    int size = 2;
    int cnt = 0;
    int time = 0;

    while (1) {
        bfs(r,c,size);
        board[r][c] = 0;

        if(!next_prey(r,c,size)) return time;

        board[r][c] = 9;
        time += dist[r][c];
        cnt ++;
        if (cnt == size) {
            cnt = 0;
            size++;
        }

        for (int i = 0; i < MAX; i++)
            memset(dist[i], -1, sizeof(int)*MAX);
    }
}

int main() {
    cin >> N;
    int r,c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9) {
                r = i;
                c = j;
            }
        }
    }

    for (int i = 0; i < MAX; i++)
        memset(dist[i], -1, sizeof(int)*MAX);

    cout << cal_time(r,c);
}

