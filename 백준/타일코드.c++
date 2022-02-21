# include <iostream>
using namespace std;

# define MAX 31
int dp[MAX] = {0,};

int func(int n) {
    if (n <= 2) return dp[n];
    if (n % 2 == 1) return dp[n/2];
    return dp[n/2] + dp[n/2-1]*2;
}

int main() {
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < MAX; i++) {
        dp[i] = dp[i-2]*2 + dp[i-1];
    }

    int N; cin >> N;
    cout << dp[N] - (dp[N] - func(N))/2;
}