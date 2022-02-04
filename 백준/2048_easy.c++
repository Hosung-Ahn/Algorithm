# include <iostream>
# include <vector>
using namespace std;

# define MAX 20

int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return true;
    return false;
}

void merge_block(int r, int c, int nr, int nc, vector<vector<int>> &board) {
    if (!in_range(nr,nc)) return;
    if (board[nr][nc] == board[r][c]) {
        board[nr][nc] *= 2;
        board[r][c] = 0;
    }
}
void move_point(int r, int c, int dir, vector<vector<int>> &board) {
    int idx = 1,nr,nc;
    while(1) {
        nr = r + dr[dir] * idx;
        nc = c + dc[dir] * idx;
        if (!in_range(nr,nc) || board[r][c] != 0) break;
        idx++;  
    }

    int r_moved = r + dr[dir] * (idx-1);
    int c_moved = c + dc[dir] * (idx-1);
    
    if (r_moved != r || c_moved != c) {
        board[r_moved][c_moved] = board[r][c];
        board[r][c] = 0;
    }
    merge_block(r_moved, c_moved, nr,nc, board);
}


void slide(int dir, vector<vector<int>> &board) {
    switch(dir) {
        case 0 :
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
        break;

        case 1 :
            for (int c = 0; c < N; c++) {
                for (int r = 0; r < N; c++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }

        case 2 :
            for (int r = N-1; r >=0; r--) {
                for (int c = 0; c < N; c++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
        
        case 3 :
            for (int c = N-1; c >= 0; c--) {
                for (int r = 0; r < N; r++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
    }
}

int main() {
    cin >> N;
    vector<vector<int>> board(MAX, vector<int>(MAX,0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x; scanf("%d", &x);
            board[i][j] = x;
        }
    }

    slide(1,board);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}