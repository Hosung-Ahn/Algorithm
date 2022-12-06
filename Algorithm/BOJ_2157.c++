#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 301
#define INF 987654321

int dp[MAX][MAX];
vector<pair<int,int>> edges[MAX];
int V,M,E;

int find_dp(int cur, int m) {
    int &ret = dp[cur][m];
    if (ret != -1) return ret;

    if (m < 0) return -INF;
    if (cur == V) return 0;

    ret = -INF;
    for(int i=0;i<edges[cur].size();i++) {
        int next = edges[cur][i].first;
        int d = edges[cur][i].second;
        ret = max(ret, d + find_dp(next, m-1));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> V >> M >> E;

    for(int i=0;i<E;i++) {
        int s,e,d; cin >> s >> e >> d;
        if (s > e) continue;
        edges[s].push_back({e,d});
    }

    cout << find_dp(1, M-1);
    
}