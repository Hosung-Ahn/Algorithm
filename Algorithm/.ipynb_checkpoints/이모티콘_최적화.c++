# include <iostream> 
using namespace std;

# define MAX 1001

int dp[MAX] = {0, };

int main() {
    int n; cin >> n;
    for (int i = 1; i < MAX; i++)
        dp[i] = i;

    for (int i = 2; i < MAX; i++) {
        for (int j = 2*i; j < MAX; j *= 2) {
            dp[j] = min(dp[j], dp[j/2] + 2);
            dp[j-1] = min(dp[j-1], dp[j] + 1);
        }

        for (int j = 2; i*j < MAX; j++) {
            dp[i*j] = min(dp[i*j], dp[i] + j);
            dp[i*j-1] = min(dp[i*j-1], dp[i*j] + 1);
        }
    }

    cout << dp[n] << endl;
}