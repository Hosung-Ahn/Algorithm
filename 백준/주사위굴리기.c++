# include <iostream>
using namespace std;

# define MAX 20

int N,M;
int board[MAX][MAX] = {0,};
int dr[] = {0,0,-1,1};
int dc[] = {1,-1,0,0};

class Dice{
public:
    int num[6] = {0,0,0,0,0,0};

    void right() {
        int num4 = num[4];
        num[4] = num[3];
        int num1 = num[1];
        num[1] = num4;
        int num5 = num[5];
        num[5] = num1;
        num[3] = num5;
    }
    void left() {
        int num1 = num[1];
        num[1] = num[5];
        int num4 = num[4];
        num[4] = num1;
        int num3 = num[3];
        num[3] = num4;
        num[5] = num3;
    }
    void down() {
        int num1 = num[1];
        num[1] = num[0];
        int num2 = num[2];
        num[2] = num1;
        int num3 = num[3];
        num[3] = num2;
        num[0] = num3;
    }
    void up() {
        int num2 = num[2];
        num[2] = num[3];
        int num1 = num[1];
        num[1] = num2;
        int num0 = num[0];
        num[0] = num1;
        num[3] = num0;
    }
};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

int main() {
    int r,c, K;
    cin >> N >> M >> r >> c >> K;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            scanf("%d", &board[r][c]);

    Dice dice;

    for (int i = 0; i < K; i++) {
        int dir; scanf("%d", &dir);
        dir--;

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (!in_range(nr,nc)) continue;

        switch (dir) {
            case 0 :
                dice.right();
                break;
            case 1 :
                dice.left();
                break;
            case 2 : 
                dice.up();
                break;
            case 3 :
                dice.down();
                break;
        }

        if (board[nr][nc] == 0) {
            board[nr][nc] = dice.num[3];
        }
        else {
            dice.num[3] = board[nr][nc];
            board[nr][nc] = 0;
        }

        cout << dice.num[1] << "\n";
        r = nr;
        c = nc;
    }
    
}