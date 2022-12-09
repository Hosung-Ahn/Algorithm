#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 5000
#define INF 987654321
int dp[MAX][MAX];
int ans = INF;
int N;
vector<int> arr;

int dfs(int lo, int hi) {
    int &ret = dp[lo][hi];
    if (ret != -1) return ret;

    if (lo >= hi) return 0;

    if (arr[lo] == arr[hi]) {
        ret = 0 + dfs(lo+1, hi-1);
    }
    else {
        ret = 1 + min(dfs(lo+1, hi), dfs(lo, hi-1));
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,N-1);
}

int main() {
    cin >> N;
    arr.resize(N);
    for(int i=0;i<N;i++) cin >> arr[i];
    solve();
}