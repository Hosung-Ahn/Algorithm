# include <iostream>

using namespace std;
# define MAX 10000

int arr[MAX+1];
int dp[MAX+1] = {0, };


int find_dp(int idx) {
    int not_choose_last = dp[idx-2] + arr[idx];
    int choose_last = dp[idx-3] + arr[idx-1] + arr[idx];

    return max(not_choose_last, choose_last);
}

int main() {
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        scanf("%d", &arr[i]);

    int result = 0;
    if (n <= 2) {
        for (int i =  1; i <= n; i++)
            result += arr[i];

        cout << result << endl;
    }

    else {
        dp[1] = arr[1];
        dp[2] = arr[1] + arr[2];
        
        for (int i = 3; i <= n; i++) {
            dp[i] = find_dp(i);
            dp[i] = max(dp[i], dp[i-1]);
        }

        cout << dp[n] << endl;
    }
}