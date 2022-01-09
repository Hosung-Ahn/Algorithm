# include <iostream>
# include <string.h>

using namespace std;

# define MAX 1500001

int arr[2][MAX];
int dp[MAX];

int N;

int find_dp(int n) {
    if (n + arr[0][n] -1 > N) {
        dp[n] = 0;
        return 0;
    }

    if (dp[n] != -1) return dp[n];

    int next_day = n + arr[0][n];
    int next_next_day = next_day + arr[0][next_day];

    int result = 0;
    for (int next_n = next_day; next_n < next_next_day; next_n++) {
        if (next_n > N) break;
        int next_dp = find_dp(next_n);
        if (next_dp > result) result = next_dp;
    }
    result += arr[1][n];
    dp[n] = result;
    return result;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) 
        scanf("%d %d", &arr[0][i], &arr[1][i]);

    
    memset(dp, -1, sizeof(int)*MAX);

    int result = 0;
    for (int i = 1; i < 1 + arr[0][1]; i++) {
        int cur = find_dp(i);
        if (cur > result) result = cur;
    }
    
    cout << result << endl;
}