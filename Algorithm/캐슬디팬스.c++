# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 16

int N,M,D;
int board[MAX][MAX] = {0,};
int dr[] = {0,-1,0};
int dc[] = {-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || c < 0 || c >= M) return false;
    return true;
}

int simulation(int x, int y, int z) {
    int board_copy[MAX][MAX] = {0,};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board_copy[i][j] = board[i][j];
        }
    }
    int pos_c[] = {x,y,z};
    int pos_r = N;
    int kill = 0;
    
    while (pos_r > 0) {
        int check[MAX][MAX] = {0,};
        
        for (int i = 0; i < 3; i++){
            int visited[MAX][MAX];

            for (int j = 0; j < MAX; j++)
                memset(visited[j], -1, sizeof(int)*MAX);
            
            int archer_r = pos_r;
            int archer_c = pos_c[i];
            visited[archer_r][archer_c] = 0;
            
            queue<pair<int,int>> q;
            q.push({archer_r, archer_c});
            while (!q.empty()) {
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();

                if (board_copy[cr][cc] == 1) {
                    check[cr][cc] = 1;
                    break;
                }

                for (int k = 0; k < 3; k++) {
                    int nr = cr + dr[k];
                    int nc = cc + dc[k];
                    if (!in_range(nr,nc) || visited[nr][nc] >= 0) continue;

                    visited[nr][nc] = visited[cr][cc] + 1;
                    if (visited[nr][nc] > D ) continue;
                    q.push({nr,nc});
                }
                
            }
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (check[i][j] == 1) {
                    kill++;
                    board_copy[i][j] = 0;
                }
            }
        }
        pos_r--;
        for (int i = 0; i < M; i++)
            board_copy[pos_r][i] = 0;
    }

    return kill;
}

int main() {
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            scanf("%d", &board[i][j]);

    int result = 0;

    for (int x = 0; x < M; x++) {
        for (int y = x+1; y < M; y++) {
            for (int z = y+1; z < M; z++) {
                result = max(result, simulation(x,y,z));
            }
        }
    }

    cout << result;
}
