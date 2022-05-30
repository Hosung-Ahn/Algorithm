# include <iostream>
using namespace std;

# define MAX 2000

int arr[MAX+1];
int dp[MAX+1] = {0,};

int find_dp(int idx, int value) {
    int max_sum = 0;
    for (int i = 1; i < idx; i++) {
        if (arr[i] > value && dp[i] > max_sum) {
            max_sum = dp[i];
        }
    }

    return max_sum;
}

int main() {
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        scanf("%d", &arr[i]);

    int max_cnt = 0; 

    for (int i = 1; i <= n; i++){
        dp[i] = find_dp(i,arr[i]) + 1;

        if (dp[i] > max_cnt)
            max_cnt = dp[i];
    }

    cout << n - max_cnt << endl;
}