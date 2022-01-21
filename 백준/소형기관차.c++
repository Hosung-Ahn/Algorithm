# include <iostream>
# include <string.h>
using namespace std;

# define MAX 50000
int dp[3][MAX];
int arr[MAX];
int N, K;

int find_dp(int cnt, int n) {
    if (cnt < 0) return 0;
    if (n >= N) return 0;
    if (dp[cnt][n] != -1) return dp[cnt][n];

    int ret = 0;
    for (int i = 0; i < K; i++) {
        if (n+i >= N) break;
        ret += arr[n+i];
    }

    ret += find_dp(cnt-1, n + K);

    ret = max(ret, find_dp(cnt, n+1));
    
    dp[cnt][n] = ret;
    return ret;
}

int main() {
    for (int i = 0; i < 3; i++)
        memset(dp[i], -1, sizeof(int)*MAX);


    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    cin >> K;

    cout << find_dp(2,0);

}