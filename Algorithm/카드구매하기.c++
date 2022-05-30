# include <iostream>
using namespace std;

# define MAX 10000

int arr[MAX+1];
int dp[MAX+1] = {0, };

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
        }
    }

    cout << dp[n] << endl;
}