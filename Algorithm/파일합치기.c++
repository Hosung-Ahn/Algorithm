# include <iostream>
# include <string.h>
using namespace std;

# define MAX 501
# define INF 987654321

int sum[MAX]= {0,};
int dp[MAX][MAX] = {0,};

int find_dp(int s, int e) {
    if (dp[s][e] != 0) return dp[s][e];
    if (s == e) return 0;
    if (s+1 == e) return sum[e] - sum[s-1];

    int result = INF;
    
    for (int mid = s; mid < e; mid++) {
        result = min(result, find_dp(s, mid) + find_dp(mid+1,e));
    }
    result += sum[e] - sum[s-1];
    dp[s][e] = result;

    // cout << s << " " << e << " " << result << endl;
    return result;
}

int main(){
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        memset(sum, 0, sizeof(int)*MAX);
        for (int i = 0; i < MAX; i++) 
            memset(dp[i], 0, sizeof(int)*MAX);

        int N; cin >> N;
        int s = 0;
        for (int i = 1; i <= N; i++) {
            int x; scanf("%d", &x);
            s += x;
            sum[i] = s;
        }
        cout << find_dp(1,N) << endl;
    }



}