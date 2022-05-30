# include <iostream>
using namespace std;

# define MAX 100001
# define MOD 9901

int dp[3][MAX] = {0,};

int find_dp(int box, int n) {
    if (dp[box][n] != 0 ) return dp[box][n];
    if (n == 1) return 1;

    int result = 0;
    switch (box) {    
        case 0 :
        case 1 : 
        for (int i = 0; i < 3; i++) {
            if (i == box ) continue;
            result += find_dp(i, n-1);
            result %= MOD;
        }
        dp[box][n] = result;
        return result;

        case 2 :
        for (int i = 0; i < 3; i++) {
            result += find_dp(i, n-1);
            result %= MOD;
        }
        dp[box][n] = result;
        return result;
    }
}


int main() {
    int n; cin >> n;
    int result = 0;
    for (int i = 0; i < 3; i++) {
        result += find_dp(i,n);
        result %= MOD;
    }

    cout << result << endl;
}