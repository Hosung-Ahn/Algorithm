# include <iostream>
# include <string.h>
using namespace std;

# define MAX 2000
int arr[MAX] = {0,};
int dp[MAX][MAX];
int N;

int dp_even(int s, int e) {
    if (s == e) return 1;
    if (arr[s] != arr[e]) {
        return 0;
    }
    if (dp[s][e] != -1) return dp[s][e];

    dp[s][e] = dp_even(s+1,e-1);
    return dp[s][e];
}

int dp_odd(int s, int e) {
    if (s+1 == e) return arr[s] == arr[e];
    if (arr[s] != arr[e]) return 0;
    if (dp[s][e] != -1) return dp[s][e];

    dp[s][e] = dp_odd(s+1, e-1);
    return dp[s][e];
}


int main() {
    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s,&e);
        if ( (e-s) % 2 == 0) cout << dp_even(s-1,e-1) << "\n";
        else cout << dp_odd(s-1,e-1) << "\n";
    }

    
}