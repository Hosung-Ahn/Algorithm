# include <iostream>
# include <cmath>
using namespace std;
# define ll long long
# define MAX 4000000+1
# define MOD 1000000007
ll fact[MAX] = {0,};

ll pow_N(ll n, int e) {
    ll ret = 1;
    while(e) {
        if (e & 1) ret = (ret*n) % MOD;
        n = (n*n)%MOD;
        e >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    fact[0] = 1;
    for (int n = 1; n < MAX; n++) {
        fact[n] = (fact[n-1]*n) % MOD;
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int N,K; cin >> N >> K;
        ll X = (fact[K] * fact[N-K]) % MOD;
        cout << (fact[N] * pow_N(X, MOD-2)) % MOD << "\n";
    }
}