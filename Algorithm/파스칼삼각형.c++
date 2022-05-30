# include <iostream>

using namespace std;

# define MAX 30

int triagle[MAX+1][MAX+1] = {0, };

void drawPascal() {
    triagle[1][1] = 1;
    for (int i = 2; i <= MAX; i++) {
        triagle[i][1] = 1;
        triagle[i][i] = 1;
    }

    for (int r = 3; r <= MAX; r++) {
        for (int c = 2; c < r; c++) {
            triagle[r][c] = triagle[r-1][c-1] + triagle[r-1][c];
        }
    }
}

int cal_sum(int r, int c, int w) {
    int ret = 0; 
    for (int i = 0; i < w; i++) {
        for (int j = 0; j <= i; j++) {
            ret += triagle[r+i][c+j];
        }
    }
    return ret;
}

int main() {
    drawPascal();

    int r,c,w; cin >> r >> c >> w;

    cout << cal_sum(r,c,w);


}