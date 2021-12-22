# include <iostream>

using namespace std;

# define MAX 1000

int arr[MAX];
int dp[MAX];

int find_d(int idx, int value) {
    int ret = 0;

    for (int i = 0; i < idx; i++) {
        if (arr[i] > value && dp[i] > ret) 
            ret = dp[i];
    }

    return ret; 
}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = find_d(i, arr[i]) + 1;
        if (dp[i] > result) 
            result = dp[i];
    }

    cout << result << endl;

}