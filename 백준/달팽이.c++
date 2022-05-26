#include <iostream>
#include <cstring>
using namespace std;
# define MAX 1000+1

double dp[MAX][MAX];

double find_dp(int n, int m) {
    // cout << n << " " << m << endl;
    if (m == 0) return n <= 0;
    if (n <= 0) return 1;

    double &ret = dp[n][m];
    if (ret > -1) return ret;

    ret = find_dp(n-2, m-1) * (0.75) + find_dp(n-1, m-1) * (0.25);
    return ret;
}

int main() {
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < MAX; i++)
            memset(dp[i], -1, sizeof(double)*MAX);

        int n,m; cin >> n >> m;
        cout<<fixed;
        cout.precision(8);
        cout << find_dp(n,m) << "\n";
    }
    

}