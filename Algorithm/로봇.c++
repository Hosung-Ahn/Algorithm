# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 100

bool board[MAX][MAX] = {0,};
int cnt[4][MAX][MAX];
int N, M;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

class Point {
public:
    int r,c,dir;
    Point(int r, int c, int dir) : r(r), c(c), dir(dir) {}
};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true; 
}

int turn_left(int dir) {
    switch (dir) {
        case 0 :
        return 3;
        case 3 :
        return 1;
        case 1 : 
        return 2;
        case 2 :
        return 0;
    }
    return -1;
}

int turn_right(int dir) {
    switch (dir) {
        case 0 :
        return 2;
        case 2 :
        return 1;
        case 1 :
        return 3;
        case 3 :
        return 0;
    }
    return -1;
}

int (*turn[])(int) = {turn_left, turn_right};

void bfs(int sr, int sc, int sdir, int er, int ec, int edir) {
    cnt[sdir][sr][sc] = 0;
    queue<Point> q;
    q.push(Point(sr,sc,sdir));

    while (!q.empty()){
        int cr = q.front().r;
        int cc = q.front().c;
        int cdir = q.front().dir;
        q.pop();

        if (er == cr && ec == cc && edir == cdir) {
            cout << cnt[edir][er][ec];
            return;
        }


        for (int k = 1; k <= 3; k++) {
            int nr = cr + dr[cdir]*k;
            int nc = cc + dc[cdir]*k;
            if (!in_range(nr,nc) || board[nr][nc] == 1)
                break;
            if (cnt[cdir][nr][nc] != -1) continue;
            cnt[cdir][nr][nc] = cnt[cdir][cr][cc] + 1;
            q.push(Point(nr,nc,cdir));
        }

        for (int i = 0; i < 2; i++) {
            int ndir = turn[i](cdir);
            if (cnt[ndir][cr][cc] != -1) continue;
            cnt[ndir][cr][cc] = cnt[cdir][cr][cc] + 1;
            q.push(Point(cr,cc,ndir));
        }

    }
}

int main() {
    cin >> N >> M;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int x; scanf("%d", &x);
            if (x == 1)
                board[r][c] = 1;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX; j++) {
            memset(cnt[i][j], -1, sizeof(int)*MAX);
        }
    }

    int sr,sc,sdir, er,ec,edir;
    scanf("%d %d %d %d %d %d", &sr, &sc, &sdir, &er, &ec, &edir);

    bfs(sr-1,sc-1,sdir-1, er-1,ec-1,edir-1);
}