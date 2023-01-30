#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 5001
#define INF 2000000000
int N,Q;
vector<pair<int,int>> edges[MAX];
int USADO[MAX][MAX];

void bfs(int start){
    queue<pair<int,int>> q;
    bool visited[MAX] = {0,};
    q.push({start, INF});
    visited[start] = true;
    while(!q.empty()) {
        int cur_node = q.front().first;
        int cur_usado = q.front().second;
        q.pop();

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first;
            int next_usado = min(cur_usado, edges[cur_node][i].second);
            if (visited[next_node]) continue;
            visited[next_node] = true;
            USADO[start][next_node] = next_usado;
            q.push({next_node, next_usado});
        }
    }
}

void print_ans(int k, int s) {
    int ans = 0;
    for(int n=1;n<=N;n++) if (n!=s && USADO[s][n] >= k) {
        ans++;
    }
    cout << ans << "\n";
}

void solve() {
    for(int n=1;n<=N;n++) {
        bfs(n);
    }
    for(int i=0;i<Q;i++) {
        int k, s; cin >> k >> s;
        print_ans(k,s);
    }
}

int main() {
    cin >> N >> Q;
    for(int i=0;i<N-1;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }
    solve();
}