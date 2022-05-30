# include <iostream>
# include <string.h>

using namespace std;

# define MAX 1500001

int arr[2][MAX];
int dp[MAX];

int N;

int find_dp(int n) {
    if (n > N) return 0;
    if (dp[n] != -1) return dp[n];

    
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) 
        scanf("%d %d", &arr[0][i], &arr[1][i]);

    
    memset(dp, -1, sizeof(int)*MAX);

    
    
}