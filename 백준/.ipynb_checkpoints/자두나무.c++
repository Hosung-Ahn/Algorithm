# include <iostream> 
# include <string.h>
using namespace std;

int T,W;
int arr[1001];

int dp[1001][31][2];

int find_dp(int t, int w, int p) {
    if (t > T || w > W) return 0; 

    if (dp[t][w][p] != -1) return dp[t][w][p];

    int result = 0;
    if (p == arr[t]) result += 1;
    result += max(find_dp(t+1, w+1, (p+1)%2), find_dp(t+1, w, p));

    dp[t][w][p] = result;
    return result;
}

int main(){
    cin >> T >> W;
    arr[0] = -1;

    for (int i =1; i<=T; i++) {
        int x; scanf("%d", &x);
        arr[i] = x - 1;
    }

    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 31; j++)
            memset(dp[i][j], -1, sizeof(int)*2);
    

    cout << find_dp(0, 0, 0) << endl;   
}