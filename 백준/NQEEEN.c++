# include <iostream>
using namespace std;
# define MAX 15

int board[MAX][MAX] = {0,};
int N;
int cnt = 0;

void set(int r, int c, bool deset = false) {
    int x = 1;
    if (deset) x = -1;

    for (int i = 1; i <= N; i++){
        board[r][i] += x;
    }
    for (int i = r + 1; i <= N; i++) {
        board[i][c] += x;
    }

    int nr = r, nc = c;
    while (nr < N && nc < N) {
        board[++nr][++nc] += x;
    }

    nr =r, nc = c;
    while (nr < N && nc > 1 ){ 
        board[++nr][--nc] += x;
    }
}

void count(int r, int queen) {
    if (queen == 0) {
        cnt++;
        return;
    }
    for (int nc = 1; nc <= N; nc++) {
        if (!board[r][nc]) {
            set(r,nc);
            count(r+1, queen - 1);
            set(r,nc, true);
        }
    }
}


int main() {
    cin >> N;
    count(1, N);
    cout << cnt;

}