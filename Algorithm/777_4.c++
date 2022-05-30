# include <iostream>
# include <math.h>
using namespace std;
int x,d; 

bool is_beautiful(int n) {
    int check = pow(n,0.5);

    for (int i = 2; i <= check; i++) {
        if (n % i == 0) {
            if (i % d == 0 && n/i % d == 0) return false;
        }
    }
    return true;
}

void solve() {
    int cnt = 0;
    int check = pow(x, 0.5);

    for (int i = 2; i <= check; i++) {
        if (x % i == 0) {
            if (is_beautiful(i) && is_beautiful(x/i)) {
                cnt++;
            }
            if (cnt >= 2) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &x, &d);
        solve();
    }
}