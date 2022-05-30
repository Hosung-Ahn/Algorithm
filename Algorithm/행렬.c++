# include <iostream>
using namespace std;

# define MAX 50

int board[MAX][MAX];
int N,M;

bool in_range(int r, int c) {
    if (r + 3 > N || c + 3 > M) return false; 
    return true;
}

void upend(int r, int c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[r+i][c+j] = !board[r+i][c+j];
        }
    }
}

void print_cnt() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                if (in_range(i,j)) {
                    upend(i,j);
                    cnt++;
                }
                else {
                    cout << -1;
                    return;
                }
            }
        }
    }
    cout << cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x; scanf("%1d", &x);

            if (x == board[i][j]) {
                board[i][j] = 1;
            }
            else board[i][j] = 0;
        }
    }

    print_cnt();
    
}