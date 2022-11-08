#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,M;
int money[301][20] = {0,};
int dp[301][20];
int path[301][21];

vector<int> arr;

int find_dp(int idx, int T) {
    int &ret = dp[T][idx];
    if (ret != -1) return ret;
    if (idx == N) return 0;

    for(int i=0;i<=T;i++) {
        int tmp = money[i][idx]+find_dp(idx+1,T-i);
        if (ret < tmp) {
            path[T][idx] = i;
            ret = tmp;
        }
    }
    return ret;
}

int main() {
    memset(dp,-1,sizeof(dp));
    memset(path,-1,sizeof(path));
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int n; cin >> n;
        for(int j=0;j<M;j++) {
            cin >> money[n][j];
        }
    }
    int ans = find_dp(0,N);
    cout << ans << endl;
    int cur = N;
    for(int i=0;i<M;i++) {
        cout << path[cur][i] << " ";
        cur = path[cur - path[cur][i]][i+1];
    }
}