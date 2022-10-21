#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAX 1000001
#define ll long long
ll dp[MAX] = {0,};

int main() {
    int n; cin >> n;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    ll sum = 31;
    for(int i=4;i<MAX;i++) {
        dp[i] = sum*2+dp[i-2]+2;
        dp[i] %= MOD;
        
        sum += dp[i];
        sum %= MOD;
    }
    cout << dp[n];
}