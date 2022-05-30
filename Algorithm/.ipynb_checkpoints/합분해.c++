# include <iostream>

using namespace std;

# define MAX 201
# define MOD 1000000000

int dp[MAX][MAX] = {0,};

int find_dp(int n, int cnt){
    if (cnt == 1) return 1;

    if (dp[n][cnt] != 0) return dp[n][cnt];


    int result = 0;

    for (int i = 0; i <= n; i++) {
        result += find_dp(i, cnt-1);
        result %= MOD;
    }

    dp[n][cnt] = result;

    return result;
}

int main() {
    int n, cnt; cin >> n >> cnt;

    cout << find_dp(n, cnt) << endl;
}