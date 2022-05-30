# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 8
int board[MAX][MAX] = {0,};
int N,M,cnt = 0;
int monitor[MAX][MAX] = {0,};
int result = 987654321;

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void set_right(int r, int c, int n) {
    int nc = c + 1;
    while (in_range(r,nc) && board[r][nc] != 6) {
        monitor[r][nc] += n;
        nc++;
    }
}
void set_down(int r, int c, int n) {
    int nr = r + 1;
    while (in_range(nr,c) && board[nr][c] != 6) {
        monitor[nr][c] += n;
        nr++;
    }
}
void set_left(int r, int c, int n) {
    int nc = c - 1;
    while (in_range(r,nc) && board[r][nc] != 6) {
        monitor[r][nc] += n;
        nc--;
    }
}
void set_up(int r, int c, int n) {
    int nr = r - 1;
    while (in_range(nr,c) && board[nr][c] != 6) {
        monitor[nr][c] += n;
        nr--;
    }
}

void (*set_dir[])(int,int,int) = {set_right, set_down, set_left, set_up};

void set(int r, int c, int type, int dir, bool unset = false) {
    int n = 1;
    if (unset) n = -1;

    switch(type) {
        case 1 : 
            set_dir[dir](r,c,n);
        break;

        case 2 :
            set_dir[dir](r,c,n);
            set_dir[dir+2](r,c,n);
        break;

        case 3 :
            set_dir[dir](r,c,n);
            set_dir[(dir+1)%4](r,c,n);
        break;

        case 4 :
            for (int i = 0; i < 3; i++)
                set_dir[(dir+i)%4](r,c,n);
        break;

        case 5 :
            for (int i = 0; i < 4; i++) 
                set_dir[i](r,c,n);
        break;
    }
}

void dfs(int idx, int n) {
    if (n==cnt) {
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0 && monitor[i][j] == 0)
                    tmp++;
            }
        }
        result = min(result, tmp);
        return;
    }
    for (int i = idx; i < N*M; i++) {
        int r = i/M;
        int c = i%M;
        int type = board[r][c];

        if (type >= 1 && type <= 5) {
            switch(type) { 
                case 2 :
                    for (int dir = 0; dir < 2; dir++) {
                        set(r,c,type,dir);
                        dfs(i+1, n+1);
                        set(r,c,type,dir,true);
                    }
                break;

                case 5 :
                    set(r,c,type,0);
                    dfs(i+1,n+1);
                    set(r,c,type,0,true);
                break;

                default :
                    for (int dir = 0; dir < 4; dir++) {
                        set(r,c,type,dir);
                        dfs(i+1, n+1);
                        set(r,c,type,dir,true);
                    }
                break;
            }
        }
        
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N ;i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] < 6) cnt++;
        }
    }

    dfs(0,0);

    cout << result;
}