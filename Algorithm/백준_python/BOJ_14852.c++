#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAX 1000001
#define ll long long
ll dp[MAX] = {0,};

ll find_dp(int n) {
    if (n==1) return 2;
    else if (n==2) return 7;
    else if (n==3) return 22;

    ll &ret = dp[n];
    if (ret != 0) return ret;

    ret += find_dp(n-1)*2;
    ret += find_dp(n-2)*3;
    ret += find_dp(n-3)*2;
    ret %= MOD;
    
    return ret; 
}

int main() {
    int n; cin >> n;
    cout << find_dp(n); 
}