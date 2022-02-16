# include <iostream>
using namespace std;

# define MAX 5001
# define MOD 1000000007
# define ll long long

ll fact[MAX] = {0,};


ll exp(int n, int p) {
    if (p == 1) return n;
    ll ret = exp(n, p/2);

    if (p % 2 == 0) return (ret * ret) % MOD;
    return ((ret * ret )% MOD )* n % MOD;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int x; scanf("%d", &x);

        if (x % 2 == 1) {
            cout << "0\n";
            continue;
        }
        cout << (fact[x] * exp((fact[x/2] * fact[x/2+1]) % MOD, MOD-2) ) % MOD<< "\n";
    }
}