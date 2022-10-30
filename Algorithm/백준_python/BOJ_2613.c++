#include <iostream>
using namespace std;
#define MAX 300
int N,M;
int arr[MAX] = {0,};
int dp[MAX][MAX] = {0,};

int find_dp(int idx, int m) {
    int cur = 0;
    int &ret = dp[idx][m];
    if (ret != 0) return ret;
    if (m==1) {
        for(int i=idx;i<N;i++) ret += arr[i];
        return ret;
    }
    ret = 987654321;
    for(int i=idx;i<=N-m;i++) {
        cur += arr[i];
        ret = min(ret,max(cur,find_dp(i+1, m-1)));
    }
    return ret;
}

void solve() { 
    int ans = find_dp(0,M);
    cout << ans << endl;
    int sum = 0, cnt = 0;
    for(int i=0;i<N;i++) {
        if (sum + arr[i] > ans) {
            cout << cnt << " ";
            sum = 0;
            cnt = 0;
            M--;
        }
        sum += arr[i];
        cnt += 1;
        if (N-i == M) {
            cout << cnt << " ";
            for(int j=0;j<N-i-1;j++) {
                cout << 1 << " ";
            }
            return;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> arr[i];
    solve();
}  