# include <iostream>
using namespace std;

# define MAX 800
int R,C;
int board[MAX][MAX] = {0,};
int lu[MAX][MAX] = {0,};
int ru[MAX][MAX] = {0,};
int ld[MAX][MAX] = {0,};
int rd[MAX][MAX] = {0,};
int diamond[MAX][MAX] = {0,};

int func(int r, int c, int k) {
    int ret = k;
    for (int i = 2*k-2; i >= 0; i-=2) {
        if (ld[r+i][c] >= ret && 
            rd[r+i][c] >= ret) 
            return ret;
        ret--;
    }
    return ret;
}

int main() {
    cin >> R >> C;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            scanf("%1d", &board[r][c]);
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (board[r][c] == 1) {
                ld[r][c] = ld[r-1][c-1]+1;
                rd[r][c] = rd[r-1][c+1]+1;
            } 
        }
    }

    for (int r = R; r >= 1; r--) {
        for (int c = 1; c <= C; c++) {
            if (board[r][c] == 1 ) {
                lu[r][c] = lu[r+1][c-1]+1;
                ru[r][c] = ru[r+1][c+1]+1;
            }
        }
    }

    int result = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            diamond[r][c] = func(r,c,min(lu[r][c], ru[r][c]));
            if (diamond[r][c] > result) {
                result = diamond[r][c];
            }
        }
    }

    cout << result;
}