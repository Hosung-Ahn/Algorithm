# include <iostream>
# include <string.h>
using namespace std;

# define MAX 31

int dp[MAX];
int N;

int find_dp(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n]; 

    int result = 0;
    result += 3 * find_dp(n-2);

    for (int i = 4; i <= n; i += 2) {
        result += 2 * find_dp(n-i);
    }

    dp[n] = result;

    return result;
}
int main() {
    cin >> N;
    memset(dp, -1, sizeof(int) * MAX);

    cout << find_dp(N) << endl;
}