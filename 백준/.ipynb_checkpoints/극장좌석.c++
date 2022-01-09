# include <iostream>
using namespace std;

# define MAX 41

int fix[MAX] = {0,};
int dp[MAX] = {0, };
int N;

int find_dp(int n) {
    if (n >= N) return 1;
    if (dp[n] != 0) return dp[n];

    if (fix[n] == 1 || fix[n+1] == 1) return find_dp(n+1);

    int result = 0;
    result += find_dp(n+1);
    result += find_dp(n+2);
    
    dp[n] = result;
    return result;
}

int main() {
    int m; cin >> N >> m;
    for (int i = 1; i <= m; i++) {
        int idx; scanf("%d", &idx);
        fix[idx] = 1;
    }

    cout << find_dp(1);
        
}