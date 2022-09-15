#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define VMAX 1001
int V,E,K;
vector<pair<int,int>> edges[VMAX];
priority_queue<int> dist[VMAX];

void dijkstra() {
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    dist[1].push(0);
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cd = -pq.top().first;
        pq.pop();

        for (int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            int nd = edges[cur][i].second + cd;

            if (dist[next].size() < K) {
                dist[next].push(nd);
                pq.push({-nd, next});
            }
            else {
                if (dist[next].top() < nd) continue;
                dist[next].pop();
                dist[next].push(nd);
                pq.push({-nd, next});
            }
        }
    }
}

void solve() {
    dijkstra();
    for(int i=1;i<=V;i++) {
        if (dist[i].size() < K) cout << -1 << "\n";
        else cout << dist[i].top() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E >> K;
    for(int i=0;i<E;i++) {
        int s,e,d; cin >> s >> e >> d;
        edges[s].push_back({e,d});
    }

    solve();
}