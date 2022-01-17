# include<iostream> 
using namespace std;

# define MAX 30
int dp[MAX] = {0,};

int main() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;

    for (int n = 4; n < MAX; n++) {
        dp[n] = dp[n-1] + dp[n-2]*4;
        for (int i = 4; i <= n; i+=2) {
            dp[n] += dp[n-i]*3;
        }
        for (int i = 3; i <=n; i+=2) {
            dp[n] += dp[n-i]*2;
        }
    }


    int T; scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int n; scanf("%d", &n);
        cout << dp[n] << endl;
    }

}