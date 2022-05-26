#include <iostream>
using namespace std;
# define MAX 100+1
# define MOD 1000000007
int dp[MAX] = {0,};

int main() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int n = 3; n < MAX; n++) {
        dp[n] = (dp[n-1] + dp[n-2]) % MOD;
    }
    
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int ret = dp[N];

        if (N%2 == 0) ret -= (dp[N/2] + dp[N/2-1]) % MOD;
        else ret -= dp[N/2];


        if (ret < 0) ret += MOD;
        cout << ret << "\n";
    }
}
