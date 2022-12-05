#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
#define INF 987654321 
int V,E;
vector<pair<int,int>> edges[MAX];
int dist[MAX];
int dist_2[MAX];
vector<pair<int,int>> ans;
int cnt = 0;

void dijkstra() {
    for(int i=0;i<MAX;i++) dist[i] = INF;
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();
        // cout << cur_node << " " << cur_dist << endl;

        if (dist[cur_node] < cur_dist) continue;

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first;
            int next_dist = cur_dist + edges[cur_node][i].second;

            if(dist[next_node] <= next_dist) continue;
            dist[next_node] = next_dist;
            pq.push({-next_dist, next_node});
        }
    }
}

void dijkstra_2() {
    for(int i=0;i<MAX;i++) dist_2[i] = INF;
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    dist_2[1] = 0;
    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(dist_2[cur_node] < cur_dist) continue;

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first; 
            int next_dist = cur_dist + edges[cur_node][i].second;

            if(dist_2[next_node] <= next_dist || next_dist != dist[next_node]) continue;
            dist_2[next_node] = next_dist;
            pq.push({-next_dist, next_node});
            ans.push_back({cur_node, next_node});
            cnt++;
        }
    }
}

void solve() {
    dijkstra(); 
    dijkstra_2();
    cout << cnt << endl;
    for(auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }

    solve();
}