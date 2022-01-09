# include <iostream>
# include <string.h>
using namespace std;

# define MAX 1000

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; t++) { 

        int arr[MAX] = {0,};
        int dp[MAX] = {0,};

        int n; cin >> n;
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int result = dp[0] = arr[0];
        
        for (int i = 1; i < n; i++){
            dp[i] = max(dp[i-1]+arr[i], arr[i]);
            if (dp[i] > result)
                result = dp[i];
        }

        cout << result << endl;
    }
}