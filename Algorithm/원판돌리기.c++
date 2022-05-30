#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
# define MAX 50

vector<vector<int>> board;
int N, M, T;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
bool visited[MAX][MAX] = {0,};

bool in_range(int r) {
    if (r < 0 || r >= N) return false;
    return true;
}

bool to_be_removed(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = (c + dc[i]) % M;
        if (nc < 0) nc += M;

        if (!in_range(nr)) continue;

        if (board[nr][nc] == board[r][c]) {
            return true;
        }
    }
    return false;
}

void bfs_remove(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c}); 
    int removed = board[r][c];
    board[r][c] = 0;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = (cc + dc[i]) % M;
            if (nc < 0) nc += M;

            if (!in_range(nr) || visited[nr][nc] || board[nr][nc] != removed) continue;

            visited[nr][nc] = true;
            board[nr][nc] = 0;
            q.push({nr,nc});
        }
    }
}

void rotation(int x, int d, int k) {
    if (d == 0) k *= -1;
    k %= M;
    if (k < 0) k += M;

    for (int r = x-1; r < N; r += x) {
        vector<int> row;
        for (int i = 0; i < M; i++) {
            row.push_back(board[r][(i + k) % M]);
        }
        board[r] = row;
    }
}

bool remove_adjacent() {
    bool ret = false;

    for (int i = 0; i < MAX; i++)
        memset(visited[i], 0, sizeof(bool)*MAX);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (visited[r][c] || board[r][c] == 0) continue;
            visited[r][c] = true;

            if (to_be_removed(r,c)) {
                ret = true;
                bfs_remove(r,c);
            }
        }
    }

    return ret;
}

void avg_oper() {
    float sum = 0;
    int cnt = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) { 
            if (board[r][c] == 0) continue;
            sum += board[r][c];
            cnt++;
        }
    }

    float avg = sum / cnt;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == 0 ) continue;

            if (board[r][c] > avg) board[r][c]--;
            else if (board[r][c] < avg) board[r][c]++;
        }
    }
}



int main() {
    cin >> N >> M >> T;
    board.resize(N);
    for (int i = 0; i < N; i++) {
        board[i].resize(M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < T; i++) {
        int x,d,k; cin >> x >> d >> k;
        rotation(x,d,k);
        if (!remove_adjacent()) avg_oper();
    }

    int result = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            result += board[r][c];
        }
    }
    cout << result;

}