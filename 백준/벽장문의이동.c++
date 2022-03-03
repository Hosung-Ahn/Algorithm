# include <iostream>
# include <string.h>
# include <math.h>
using namespace std;

int dp[20][21][21];
int arr[20] = {0,};
int N,K;

void swap(int &a, int &b) { 
    int tmp = a;
    a = b;
    b = tmp;
}

int find_dp(int idx, int a, int b) {
    if (a > b) swap(a,b);
    if (idx == K) return 0;
    if (dp[idx][a][b] != -1) return dp[idx][a][b];

    if (a == arr[idx] || b == arr[idx]) return find_dp(idx+1, a,b);

    int a_change = abs(a - arr[idx]) + find_dp(idx+1, arr[idx], b);
    int b_change = abs(b - arr[idx]) + find_dp(idx+1, a, arr[idx]);

    int result = min(a_change, b_change);
    dp[idx][a][b] = result;
    return result;
}

int main() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 21; j++) {
            memset(dp[i][j], -1, sizeof(int)*21);
        }
    }

    int a,b;
    cin >> N >> a >> b >> K;

    for (int i = 0; i < K; i++) { 
        scanf("%d", &arr[i]);
    }

    cout << find_dp(0,a,b);



}