# include <iostream>
using namespace std;

# define MAX 1001
# define INF 987654321

int N;
int arr[MAX];
int dp[MAX] = {0, };

int find_dp(int n) {
    if (n == 0 ) return 0;
    if (n < 0 ) return INF;
    if (dp[n] != 0 ) return dp[n];

    int result = INF;

    for (int i = 1; i <= N; i++) {
        result = min ( result , arr[i] + find_dp(n-i) ) ; 
    }

    dp[n] = result;
    return result;
}


int main() {
    cin >> N; 

    for (int i = 1; i <= N; i++) 
        scanf("%d", &arr[i]);

    cout << find_dp(N);
    
}