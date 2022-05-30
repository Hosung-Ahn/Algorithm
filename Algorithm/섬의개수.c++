# include <iostream> 
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 50

int board[MAX][MAX] = {0, };
int R,C;
int cnt = 0;
int dr[] = {0,1,1,1,0,-1,-1,-1};
int dc[] = {1,1,0,-1,-1,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return false;
    return true;
}

void bfs(int r, int c) {
    board[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    while (!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == 0) continue;
            board[nr][nc] = 0;
            q.push({nr,nc});
        }
    }
}

bool find_next_start(int &r, int &c) {
    for (int nr = 0; nr < R; nr++) {
        for (int nc = 0; nc < C; nc++) {
            if (board[nr][nc] == 1) {
                r = nr;
                c = nc;
                cnt++;
                return true;
            }
        }
    }
    return false;
}

void clear() {
    for (int i = 0; i < MAX; i++)
        memset(board[i], 0, sizeof(int)*MAX);
    cnt = 0;
}

int main() {
    cin >> C >> R;
    while (C != 0) {
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                scanf("%d", &board[r][c]);

        
        int r, c;
        while (find_next_start(r,c)) {
            bfs(r,c);
        }

        cout << cnt << "\n";

        cin >> C >> R;
        clear();
    }
    
}