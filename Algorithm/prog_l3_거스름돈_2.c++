#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MOD 100000007

int solution(int n, vector<int> money) {
    int dp[100001] = {0,};
    dp[0] = 1;
    for(int m : money) {
        for(int p=m;p<=n;p++) {
            dp[p] += dp[p-m];
            dp[p] %= MOD;
        }
    }
    return dp[n];
}

int main() {
    vector<int> arr={1,2,5};
    cout << solution(5, arr);
}