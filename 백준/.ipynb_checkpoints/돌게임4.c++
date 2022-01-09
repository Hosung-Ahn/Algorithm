# include <iostream>
using namespace std;

# define MAX 1001

int dp[MAX] = {0, };
int N;


int find_dp(int n) {
    if (n == 0) return 1;

    if (dp[n] != 0) return dp[n];

    for (int i = 1; i <= 4; i++) {
        if ( i == 2 ) continue;

        if ( find_dp(n-i) == -1) {
            dp[n] = 1;
            return 1;
        }
    }

    dp[n] = -1;
    return -1;
}

int main() {
    cin >> N;

    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 1;

    if ( find_dp(N) == 1 ) cout << "SK";
    else cout << "CY";
}