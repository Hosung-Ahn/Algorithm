# include <iostream>
using namespace std;

# define MAX 100000

int dp[MAX] = {0, };
int dp_r[MAX] = {0,};

bool is_removed = false;

int arr[MAX];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    int result = dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        dp_r[i] = max(dp[i-1], dp_r[i-1] + arr[i]);

        result = max(dp[i], max(dp_r[i], result));
    }

    cout << result << endl;
    
}