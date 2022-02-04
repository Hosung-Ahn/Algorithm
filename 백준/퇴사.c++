# include <iostream>
using namespace std;

# define MAX 21
int T[MAX];
int P[MAX];

int dp[MAX] = {0,};
int N;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t,p; scanf("%d %d", &t, &p);
        T[i] = t;
        P[i] = p;
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        dp[i+T[i]-1] = max(dp[i+T[i]-1], dp[i-1] + P[i]);
        result = max(result, dp[i]);
        dp[i] = result;
    }

    cout << result;
}