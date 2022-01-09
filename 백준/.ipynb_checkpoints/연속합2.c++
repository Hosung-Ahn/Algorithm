# include <iostream>
using namespace std;

# define MAX 100000

int dp[MAX] = {0,}; 
int arr[MAX];
bool is_removed = false;

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);

    int result = dp[0] = arr[0];

    int removed_num;

    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + arr[i];
        if (arr[i] > dp[i]) {
            dp[i] = arr[i];
            is_removed = false;
        }
        
        if (arr[i] < 0) {
            if (!is_removed) {
                dp[i] = dp[i-1];
                removed_num = arr[i];
                is_removed = true;
            }
            else {
                if (arr[i] < removed_num) {
                    dp[i] = dp[i-1] + removed_num;
                    removed_num = arr[i];
                }
            }
        }
        if (dp[i] > result) result = dp[i];
    }

    cout << result << endl;
}