#include<iostream>
#include<cmath>
using namespace std;
#define MAX 2200

bool board[MAX][MAX] = {0,};

void dot(int r, int c, int k) {
    if (k == 1) {
        board[r][c] = true;
        return;
    }

    int nk = k/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            int nr = r + i*nk;
            int nc = c + j*nk;
            dot(nr,nc,nk);
        }
    }
}

int main() {
    int n; cin >> n;
    dot(0,0,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "*" : " ");
        }
        cout << "\n";
    }
    
}