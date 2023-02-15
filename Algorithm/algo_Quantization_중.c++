#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 100
#define INF 98765432100

ll dp[MAX][11];
int N, K;
vector<int> arr;

ll sq_sum(int mean, int start, int end) {
    ll ret = 0;
    for(int i=start;i<=end;i++) {
        ret += (arr[i]-mean) * (arr[i]-mean);
    }
    return ret;
}

ll find_dp(int idx, int k) {
    ll &ret = dp[idx][k];
    if (ret != -1) return ret;
    if (k < 0) return INF;
    if (idx == N) return 0;

    double sum = 0;
    ret = INF;

    for(int i=idx;i<N;i++) {
        sum += arr[i];
        int mean = round(sum / (i-idx+1));
        ret = min(ret, sq_sum(mean, idx, i) + find_dp(i+1, k-1));
    }
    return ret;
}

void solve() {
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    arr.clear();
    arr.resize(N, 0);
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cout << find_dp(0,K) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}