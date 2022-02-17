# include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int solve(int a, int b) {
    int c = b / a;
    while (a != 1) {
        c++;
        a = a*c - b;
        b = b*c;
        
        int d = gcd(a,b);
        a /= d;
        b /= d;

        c = b / a;
    }
    return b;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int a,b; scanf("%d %d", &a, &b);
        cout << solve(a,b) << "\n";
    }
}