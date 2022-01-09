# include <iostream>
using namespace std;

int dp[10001] = {0, };
int nums[100];
int n,k;


void myInput() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        scanf("%d", &nums[i]);
    dp[0] = 1;
}

void solve() {
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        
        for (int next = num; next <= k; next++) 
            dp[next] += dp[next-num];
    }

    cout << dp[k] << endl;
}

int main() {
    myInput();
    solve();
}