#include <iostream>
using namespace std;

#define MOD 10007
#define MAX 1001

int dp[MAX][MAX] = {0,};

int comb(int n, int k) {
    if (n==k || k == 0) return 1;
    int &ret = dp[n][k];
    if (ret != 0) return ret;

    ret = comb(n-1,k) + comb(n-1, k-1);
    ret %= MOD;
    return ret;
}

int main() {
    int n,k; cin >> n >> k;
    cout << comb(n,k);
}