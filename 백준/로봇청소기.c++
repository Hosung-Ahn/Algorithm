# include <iostream>
using namespace std;

# define MAX 50

int board[MAX][MAX];
int N,M;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}


//board = 2 -> cleaned
bool find_next(int &r, int &c, int &d) {
    for (int i = 1; i <= 4; i++) {
        int nd;
        d - i < 0 ? nd = d - i + 4 : nd = d - i;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if (!in_range(nr,nc) || board[nr][nc] >= 1) continue;
        r = nr;
        c = nc;
        d = nd;
        return true;
    }

    int d_back = (d + 2) % 4;
    int r_back = r + dr[d_back];
    int c_back = c + dc[d_back];

    if (in_range(r_back, c_back) && board[r_back][c_back] == 2) {
        r = r_back;
        c = c_back;
        return true;
    }
    return false;
}

int main() {
    cin >> N >> M;
    int sr,sc,sd; scanf("%d %d %d", &sr, &sc, &sd);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            scanf("%d", &board[r][c]);
        }
    }

    int cnt = 0;

    do {
        if (board[sr][sc] == 0) {
            cnt++;
            board[sr][sc] = 2;
        }
    } while(find_next(sr,sc,sd));

    cout << cnt;
}