#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 

#define INF 987654321
#define MAX 10001
vector<int> dist(MAX, INF);
vector<pair<int,int>> edges[MAX];
int N,D,C;

void dijstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        // 방문 여부 대체
        if (dist[cur] < cur_dist) continue;

        for (int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            int next_dist = cur_dist+edges[cur][i].second;

            if (next_dist >= dist[next]) continue;

            dist[next] = next_dist;
            pq.push({-next_dist, next});
        }
    }
}

void solve() {
    int cnt = 0;
    int ans = 0;
    for(int n=1;n<=N;n++) {
        if (dist[n] == INF) continue;
        ans = max(ans, dist[n]);
        cnt++;
    }
    cout << cnt << " " << ans << "\n";
}

void clear() {
    fill(dist.begin(), dist.end(), INF);
    for(int i=0;i<MAX;i++) edges[i].clear();
}

int main() { 
    int T; cin>> T;
    while(T--) {
        cin >> N >> D >> C;
        for (int i=0;i<D;i++){
            int a,b,d; cin >> a >> b >> d;
            edges[b].push_back({a,d});
        }
        dijstra(C);
        solve();
        clear();
    }
}