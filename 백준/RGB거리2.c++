# include <iostream>
# include <string.h>
using namespace std;

# define MAX 1000
# define INF 10000000

int arr[3][MAX];
int dp[3][MAX];
int N; 

int color(int start) {
    for (int i = 0; i < 3; i++)
        memset(dp[i], 0, sizeof(int)*MAX);

    for (int i = 0; i < 2; i++) {
        for (int c = 0; c < 3; c++) {
            dp[c][i] = INF;
        }
    }
    dp[start][0] = arr[start][0];

    for (int i = 1; i < N; i++) {
        for (int c = 0; c < 3; c++) {
            int total = INF;

            for (int lc = 0; lc < 3; lc++) {
                if (c == lc) continue;
                total = min(total, dp[lc][i-1]);
            }
            dp[c][i] = total + arr[c][i];
        }
    }

    int result = INF;
    for (int c = 0; c < 3; c++) {
        if (c == start) continue;
        result = min(result, dp[c][N-1]);
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) 
        scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);

    cout << min(color(0), min(color(1), color(2))); 
    
}

