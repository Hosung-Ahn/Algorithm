# include <iostream>
using namespace std;

# define MAX 10001

int dp[MAX] = {0,};

int main() {
    dp[0] = 1;

    for (int num = 1; num <= 3; num++) {
        for (int next = num; next < MAX; next++) {
            dp[next] += dp[next-num];
        }
    }

    int T; scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int n; scanf("%d", &n);
        cout << dp[n] << endl;
    }
    
}