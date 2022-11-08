#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,M;
int dp[301][21];
int money[301][21];
int path[301][21];

int find_dp(int cur, int T) {
    int &ret = dp[T][cur];
    if (ret != -1) return ret;
    if (cur == M) return 0;

    for(int i=0;i<=T;i++) {
        int tmp = money[i][cur]+find_dp(cur+1, T-i);
        if(ret < tmp) {
            ret = tmp;
            path[T][cur] = i;
        }
    }
    return ret;
}

void trace(int cur, int T) {
    if (cur == M) return;
    int ans = path[T][cur];
    cout << ans << " ";
    trace(cur+1, T-ans);
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int a; cin >> a;
        for(int j=0;j<M;j++) {
            cin >> money[a][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << find_dp(0,N) << endl;
    trace(0,N);
}