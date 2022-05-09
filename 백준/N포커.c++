# include <iostream>
using namespace std;
# define MOD 10007

int dp[53][53] = {0,};

int nCk(int n, int k) {
    if (n < k) return 0;
    if (k == 0) return 1;
    int &ret = dp[n][k];
    if (ret != 0) return ret;

    ret = nCk(n-1, k) % MOD + nCk(n-1,k-1) % MOD;
    ret %= MOD;
    return ret;
}

int cal(int n) {
    int k = n / 4;

    int ret = 0;
    int m = 1;
    for (int i = 1; i <= k; i++) {
        ret += (nCk(13,i) * nCk(52-4*i, n-4*i) % MOD) * m + MOD;
        m *= -1;
        ret %= MOD;
    }
    return ret;
}

int main() {
    int n; cin >> n;
    cout << cal(n);
}