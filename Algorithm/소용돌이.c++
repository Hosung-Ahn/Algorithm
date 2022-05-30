# include <iostream> 
# include <math.h>
using namespace std;

int board[50][5];

int func(int a, int b){ 
    int n = max(abs(a), abs(b));

    if (abs(a) < abs(b)) {
        if (b > 0) {
            return (2*n-1) * (2*n-1) + abs(a-b);
        }
        else return (2*n-1) * (2*n-1) + 4*n + (a-b);
    }
    else {
        if (a > 0) {
            return (2*n-1) * (2*n-1) + 6*n + a+b;
        }
        else return (2*n-1) * (2*n-1) + 2*n + abs(a+b);
    }
}

int len(int n) {
    int ret = 0;
    while (n != 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

void print(int n, int len) {
    int tmp = n;
    int n_len = 0;
    while (tmp != 0) {
        n_len++;
        tmp/=10;
    }

    for (int i = 0; i < len-n_len; i++) {
        cout << " ";
    }
    cout << n << " ";
}

int main() {
    int a1,b1,a2,b2; cin >> a1 >> b1 >> a2 >> b2;
    int max_len = 0;
    for (int i = 0; i <= a2 - a1; i++) {
        for (int j = 0; j <= b2 - b1; j++) {
            board[i][j] = func(i + a1, j + b1);
            max_len = max(max_len, len(board[i][j]));
        }
    }

    for (int i = 0; i <= a2 - a1; i++) {
        for (int j = 0; j <= b2 - b1; j++) {
            print(board[i][j], max_len);
        }
        cout << "\n";
    }
}