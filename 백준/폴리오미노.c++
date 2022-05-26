#include <iostream>
#include <cstring>
using namespace std;
# define MAX 101
# define MOD 10000000

int dp[MAX][MAX];
int find_dp(int first, int n) {
    if (first == n) return 1;
    int &ret = dp[first][n];
    if (ret != -1) return ret;

    ret = 0;
    for (int second = 1; first+second <= n; second++) {
        int k = first == 0 ? 1 : (first+second-1);
        ret += k * find_dp(second, n-first);
        ret %= MOD;
    }
    return ret;
}

int main() {
    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*MAX);
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        cout << find_dp(0,n) << "\n";
    }
}