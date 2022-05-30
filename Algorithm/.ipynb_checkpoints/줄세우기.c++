# include<iostream>
using namespace std;

# define MAX 200

int arr[MAX];
int dp[MAX];

int find_dp(int idx, int value) {
    int max_dp = 0;
    for (int i = 0; i < idx; i++) {
        if (arr[i] < value && dp[i] > max_dp) max_dp = dp[i];
    }
    return max_dp;
}


int main() {
    int n; cin >> n;
    for (int i= 0; i < n; i++)
        scanf("%d", &arr[i]);

    int total_max = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = find_dp(i, arr[i]) +1 ;
        if (dp[i] > total_max)  total_max = dp[i];
    }

    cout << n - total_max << endl;

    
}