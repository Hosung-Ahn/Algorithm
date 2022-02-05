# include <iostream>
# include <string>
using namespace std;

# define MAX 101
# define INF 1000000000

int dp[MAX][MAX] = {0,};
string result;

bool dp_print(int n, int m, int k) {
    if (n == 0) {
        if (k != 1) return false;

        while (m != 0) {
            result.push_back('z');
            m--;
        }
        return true;
    }
    if (m == 0) {
        if (k != 1) return false;

        while (n != 0) {
            result.push_back('a');
            n--;
        }
        return true;
    }

    int left = dp[n-1][m];
    int right = dp[n][m-1];

    if (k <= left) {
        result.push_back('a');
        return dp_print(n-1, m, k);
    }
    else {
        result.push_back('z');
        return dp_print(n,m-1, k-left);
    }
}

int main() {
    int N,M,K; cin >> N >> M >> K; 

    for (int i = 1; i < MAX; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if (dp[i][j] > INF) dp[i][j] = INF;
        }
    }

    if (dp_print(N,M,K)) {
        cout << result;
    }
    else cout << -1;

}