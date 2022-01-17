# include <iostream>
# include <string.h>
using namespace std;

# define MAX 101
# define MOD 1000000000

int dp[MAX][10];
bool check[10] = {0,};
int N; 

int all_used() {
    for (int n = 0; n < 10; n++) {
        if (!check[n]) return false;
    }
    return true;
}

int find_dp(int nst, int n) {
    if (n < 0 || n > 10) return 0;
    if (nst > N) {
        cout << "base case!~" << endl;
        if (all_used()) return 1;
        else return 0;
    }
    // if (dp[nst][n] != -1) return dp[nst][n];

    check[n] = true;
    cout << nst << " " << n << endl;
    int result = find_dp(nst+1, n+1) + find_dp(nst+1, n-1);
    check[n] = false;

    dp[nst][n] = result;
    return result;

}

int main() {
    cin >> N;

    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*10);

    int result = 0;

    for (int first_num = 1; first_num < 10; first_num++) {
        result += find_dp(1, first_num);
    }
    cout << result << endl;

    

}