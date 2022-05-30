# include <iostream>
using namespace std;

# define MOD 1000000007LL
# define ll long long

ll factorial(int n) {
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

ll exp(int n, int p) {
    if (p == 1) return n;

    ll ret = exp(n,p/2);
    if (p % 2 == 0) {
        return (ret * ret) % MOD;
    }
    return ( ((ret * ret) % MOD ) * n) % MOD;
}

int main() {
    int N,K; cin >> N >> K;

    cout << ( factorial(N) * exp ( (factorial(N-K) * factorial(K))%MOD, MOD-2) ) % MOD;
}