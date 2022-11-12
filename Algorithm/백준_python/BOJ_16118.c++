#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define INF 9876543210
#define MAX 4001

ll dist0[MAX];
ll dist1[2][MAX];
vector<pair<int,int>> edges[MAX];
int V,E;

struct Node1 {
    int node,k;
    ll dist;
    Node1(int node, ll dist, int k) : node(node), dist(dist), k(k) { }

    bool operator<(const Node1 &other) const {
        return dist > other.dist;
    }
};

void dijkstra_0() {
    priority_queue<pair<ll,int>> pq;
    pq.push({0,1});
    dist0[1] = 0;
    while(!pq.empty()) {
        int cur_node = pq.top().second;
        ll cur_dist = -pq.top().first;
        pq.pop();

        if (dist0[cur_node] < cur_dist) continue;
        
        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first;
            ll next_dist = cur_dist + edges[cur_node][i].second;
            if (dist0[next_node] <= next_dist) continue;
            dist0[next_node] = next_dist;
            pq.push({-next_dist, next_node});
        }
    }
}

void dijkstra_1() {
    priority_queue<Node1> pq;
    pq.push(Node1(1,0,0));
    dist1[0][1] = 0;
    while(!pq.empty()) {
        int cur_node = pq.top().node; 
        ll cur_dist = pq.top().dist;
        int cur_k = pq.top().k;
        pq.pop();

        if (dist1[cur_k][cur_node] < cur_dist) continue;

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first;
            int next_k = (cur_k+1)%2;

            int sub_dist;
            if (next_k == 1) sub_dist = edges[cur_node][i].second / 2;
            else sub_dist = edges[cur_node][i].second * 2;
            ll next_dist = cur_dist + sub_dist;

            if(dist1[next_k][next_node] <= next_dist) continue;
            dist1[next_k][next_node] = next_dist;
            pq.push(Node1(next_node, next_dist, next_k));
        }   
    }
}

void solve() {
    for(int i=0;i<MAX;i++) dist0[i]=INF;
    for(int i=0;i<2;i++)for(int j=0;j<MAX;j++) dist1[i][j]=INF;

    dijkstra_0();
    dijkstra_1();

    int ans = 0;
    for(int n=1;n<=V;n++) {
        ll d0 = dist0[n];
        ll d1 = min(dist1[0][n], dist1[1][n]);

        // cout << n << " : " << d0 << " " << d1 << endl;

        if (d0 < d1) ans++;
    }
    cout << ans;
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b,2*c});
        edges[b].push_back({a,2*c});
    }
    solve();
}