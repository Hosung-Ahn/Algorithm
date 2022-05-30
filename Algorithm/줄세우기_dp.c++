# include <iostream>
using namespace std;

# define MAX 1000001
int dp[MAX] = {0,};

int main() {
    int N; cin >> N;

    int result = 0;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        dp[x] = dp[x-1] + 1;
        if (result < dp[x]) result = dp[x];
    }

    cout << N-result << endl;
}