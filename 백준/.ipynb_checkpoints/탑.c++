# include <iostream>
# include <string.h>
using namespace std;

# define MAX 500001
int arr[MAX] ={0,};
int dp[MAX];

int find_dp(const int &h, const int &i) {
    if (i == 0) return 0; 
    if (arr[i] > h) return i;

    if (dp[i] != -1) return find_dp(h,dp[i]);
    return find_dp(h, i-1);
}

int main() {

    int n,h,idx = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        scanf("%d", &arr[i]);
    
    memset(dp, -1, sizeof(int)*MAX);

    for (int i = 1; i <= n; i++) {
        dp[i] = find_dp(arr[i], i);
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }

}