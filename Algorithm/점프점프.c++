# include <iostream>
using namespace std;

# define MAX 1000
# define INF 2000

int arr[MAX];
int dp[MAX] = {0,};
int n;


int find_dp(int idx){
    if (idx == n-1) return 0;
    if (dp[idx] != 0) return dp[idx];

    int min_dp = INF;

    for (int i = idx+1; i <= idx + arr[idx]; i++) {
        if (i < n) {
            dp[i] = find_dp(i);
            if (dp[i] < min_dp) min_dp = dp[i];
        }
    }
    dp[idx] = min_dp+1;
    return dp[idx];
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = find_dp(0);

    if (result >= INF) cout << -1 << endl;
    else cout << result << endl;
}