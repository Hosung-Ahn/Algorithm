# include <iostream>
using namespace std;
///asdasdasd
# define MAX 3072

bool board[MAX+1][2*MAX+1];

void doc(int r, int c) {
    for (int i = 0; i < 5; i++) {
        board[r][c+i] = true;
    }
    board[r-1][c+1] = true;
    board[r-1][c+3] = true;
    board[r-2][c+2] = true;
}

void doc_star(int n, int r, int c) {
    if (n == 3) {
        doc(r,c);
        return;
    }
    doc_star(n/2, r, c);
    doc_star(n/2, r, c + n);
    doc_star(n/2, r - n/2, c + n/2);
}

int main() {
    int n;
    scanf("%d", &n);

    doc_star(n,n,1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*n; j++) {
            if (board[i][j]) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}