# include <iostream>
# include <string.h>
using namespace std;

# define MAX 100
# define ll long long

int arr[MAX];
ll dp[MAX][21];

ll find_dp(int n, int k) {
    if (k < 0 || k > 20) return 0;
    if (n == 0) {
        if (arr[0] == k) return 1;
        else return 0;
    }

    if (dp[n][k] != -1) return dp[n][k];

    ll result = 0;
    result += find_dp(n-1, k - arr[n]);
    result += find_dp(n-1, k + arr[n]);

    dp[n][k] = result;
    return result;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(ll)*21);

    ll result = find_dp(n-2, arr[n-1]);

    cout << result << endl;
}