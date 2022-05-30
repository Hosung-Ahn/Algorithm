# include <iostream>
# include <string.h>
using namespace std;

# define MOD 1000000000
# define END (1 << 10)
int dp[101][10][END];
int N;

int find_dp(int n, int k, int visited) {
    if (k < 0 || k > 9) return 0;

    if (n == N) {
        if (visited == END-1) return 1;
        return 0;
    }

    if (dp[n][k][visited] != -1) return dp[n][k][visited];

    int result = find_dp(n+1, k-1, visited | 1 << (k-1)) 
                + find_dp(n+1, k+1, visited | 1 << (k+1));

    result %= MOD;
    dp[n][k][visited] = result;
    return result;
}

int main() {

    cin >> N;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 10; j++) {
            memset(dp[i][j], -1, sizeof(int)*(END));
        }
    }

    int result = 0;
    for (int i = 1; i < 10; i++) {
        result += find_dp(1, i, 1 << i);
        result %= MOD;
    }

    cout << result;
}