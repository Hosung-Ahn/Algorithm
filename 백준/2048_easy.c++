# include <iostream>
# include <vector>
# include <string.h>
using namespace std;

# define MAX 20

int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int result = 0;
bool visited[MAX][MAX] = {0,};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

void merge_block(int r, int c, int nr, int nc, vector<vector<int>> &board) {
    if (!in_range(nr,nc)) return;
    if (board[nr][nc] == board[r][c]) {
        if (visited[nr][nc]) return;
        visited[nr][nc] = true;
        board[nr][nc] *= 2;
        board[r][c] = 0;
    }
}
void move_point(int r, int c, int dir, vector<vector<int>> &board) {
    
    int idx = 1,nr,nc;
    while(1) {
        nr = r + dr[dir] * idx;
        nc = c + dc[dir] * idx;
        if (!in_range(nr,nc) || board[nr][nc] != 0) break;
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

void clear() {
    for (int i = 0; i < MAX; i++)
        memset(visited[i], 0, sizeof(bool)*MAX);
}


void slide(int dir, vector<vector<int>> &board) {
    clear();

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
                for (int r = 0; r < N; r++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
        break;

        case 2 :
            for (int r = N-1; r >= 0; r--) {
                for (int c = 0; c < N; c++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
        break;
        
        case 3 :
            for (int c = N-1; c >= 0; c--) {
                for (int r = 0; r < N; r++) {
                    if (board[r][c] != 0) move_point(r,c,dir,board);
                }
            }
        break;
    }
}

void find_result(int cnt, vector<vector<int>> &board) {
    int max_num = 0;

    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] > max_num) {
                    max_num = board[i][j];
                }
            }
        }
        result = max(result, max_num);
        return;
    }

    vector<vector<int>> board_copy = board;

    for (int i = 0; i < 4; i++) {
        slide(i,board);
        find_result(cnt+1, board);
        board = board_copy;
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

    find_result(0,board);
    cout << result << endl;

    // slide(1,board);
    // slide(1,board);

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}