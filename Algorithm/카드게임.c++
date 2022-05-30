# include <iostream>
# include <string.h>
using namespace std;
# define MAX 1000

int arr[MAX];
int result[MAX];
int dp[MAX][MAX] = {0,};

int find_dp(int left, int right) {
    if (right - left == 1) return max(arr[left], arr[right]);
    if (left == right) return arr[left];

    if (dp[left][right] != 0) return dp[left][right];

    int left_choose = arr[left] + min(find_dp(left+2, right), find_dp(left+1, right-1));
    int right_choose = arr[right] + min(find_dp(left+1, right-1), find_dp(left, right-2));
    dp[left][right] = max(left_choose, right_choose);
    return dp[left][right];
}

void clear_dp() {
    for (int i = 0; i < MAX; i++)
        memset(dp[i], 0, sizeof(int)*MAX);
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        for (int i = 0; i < N; i++)
            scanf("%d", &arr[i]);
        cout << find_dp(0,N-1) << "\n";
        clear_dp();
    }
}