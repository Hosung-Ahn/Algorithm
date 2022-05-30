# include <iostream>
# include <math.h>
using namespace std;

# define ll long long

ll exp(int n, int e, int mod) {
    if (e == 0) return 1;

    ll tmp = exp(n, e/2, mod);
    if (e % 2 == 0) {
        return (tmp*tmp) % mod;
    }
    else {
        return (((tmp*tmp) % mod) * n) % mod;
    }
}

int euler(int n) {
    int ret = n;
    for (int d = 2; d * d <= n; d++){
        if (n % d == 0) {
            ret /= d;
            ret *= d-1;

            while (n % d == 0) {
                n /= d;
            }
        }
    }
    if (n != 1) return ret/n*(n-1);
    return ret;
}

int gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int K,C; scanf("%d %d", &K, &C);
        if (gcd(K,C) != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        if (K == 1 && C == 1) cout << "2\n";
        else if (C == 1) {
            if (K+1 > 1e9) cout << "IMPOSSIBLE\n";
            else cout << K+1 << "\n";
        }
        else if (K == 1) {
            if (C > 2) cout << "IMPOSSIBLE\n";
            else cout << "1\n";
        }
        else {
            ll ans = exp(C, euler(K)-1, K);
            if (ans > 1e9) cout << "IMPOSSIBLE\n";
            else cout << ans << "\n";
        }
    }    
}