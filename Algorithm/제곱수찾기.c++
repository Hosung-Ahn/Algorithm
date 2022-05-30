# include <iostream>
# include <vector>
# include <string>
# include <math.h>
using namespace std;

vector<string> board;
int N,M;

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

bool is_square(int n) {
    int d = pow(n, 0.5);
    return d*d == n;
}

void func(int r, int c, int a, int b, int &result) {
    string n = "";
    while (in_range(r,c)) {
        n += board[r][c];
        r += a;
        c += b;
        int tmp = stoi(n);
        if (is_square(tmp)) {
            result = max(result, tmp);
        }
    }
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string s; cin >> s;
        board.push_back(s);
    }

    int result = -1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            for (int a = -8; a < 9; a++) {
                for (int b = -8; b < 9; b++) {
                    if (a == 0 && b == 0) continue;
                    func(r,c,a,b,result);
                }
            }
        }
    }
    cout << result;

}