#include <iostream>
#include <vector> 
using namespace std;
#define MAX 101
int in_degree[MAX] = {0,};
vector<pair<int,int>> edges[MAX];
int V,E;
int ans[MAX] = {0,};
int dp[MAX] = {0,};

void topology_sort(int cur_node) {
    if (edges[cur_node].empty()) {
        ans[cur_node] += dp[cur_node];
        return;
    }
    for(int i=0;i<edges[cur_node].size();i++) {
        int next_node = edges[cur_node][i].first;
        dp[next_node] += dp[cur_node] * edges[cur_node][i].second;
        if (--in_degree[next_node] == 0) {
            topology_sort(next_node);
        }
    }
}

void solve() {
    dp[V] = 1;
    topology_sort(V);
    for(int n=1;n<=V;n++) if(ans[n]!=0) {
        cout << n << " " << ans[n] << "\n";
    }
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
        in_degree[b]++;
    }
    solve(); 
}