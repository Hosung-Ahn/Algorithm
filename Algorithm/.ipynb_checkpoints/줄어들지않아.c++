# include <iostream> 
# include <string.h>
using namespace std;

# define ll long long

ll dp[10][65] = {0,};

ll find_dp(int n, int nst, int last_nst) {
    if (nst == last_nst) return 1;
    if (dp[n][nst] != 0) return dp[n][nst];

    ll result = 0;
    for (int next_n = n; next_n <= 9; next_n++) {
        result += find_dp(next_n, nst+1, last_nst);
    }

    dp[n][nst] = result;

    return result;
}

void clear_dp() {
    for (int i = 0; i < 10; i++) 
        memset(dp[i], 0, sizeof(ll)*65);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        cout << find_dp(0,0,x) << "\n";
        clear_dp();
    }
}