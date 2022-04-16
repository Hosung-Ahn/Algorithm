# include <iostream>
# include <math.h>
using namespace std;

int func(int s, int N, int K, int r, int c) {
    if (s == 0) return 0;
    int t = pow(N,s-1);
    int left = (N-K)/2 * t;
    int right = (N+K)/2 * t;

    if (r >= left && r < right && c >= left && c < right) return 1;
    return func(s-1, N,K,r%t,c%t);
}

int main() {
    int s,N,K,r1,r2,c1,c2;
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

    for (int r = 0; r <= r2-r1; r++) {
        for (int c = 0; c <= c2-c1; c++) {
            cout << func(s,N,K,r+r1,c+c1);
        }
        cout << "\n";
    }
}