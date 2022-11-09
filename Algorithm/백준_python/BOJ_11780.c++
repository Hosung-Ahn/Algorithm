#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
#define INF 987654321

int dist[MAX][MAX] = {0,};
vector<pair<int,int>> edges[MAX];
vector<int> ans[MAX][MAX];
int V,E;

struct Node{
    int node, dist;
    vector<int> path;
    Node(int _node, int _dist, vector<int> _path) {
        node = _node;
        dist = _dist;
        path = _path;
        path.push_back(node);
    }
    
    bool operator< (const Node &other) const {
        return dist > other.dist;
    }
};

void dijktra(int start) {
    priority_queue<Node> pq;
    pq.push(Node(start, 0, vector<int>()));
    while(!pq.empty()) {
        int cur_node = pq.top().node;
        int cur_dist = pq.top().dist;
        vector<int> cur_path = pq.top().path;
        pq.pop();

        if (dist[start][cur_node] < cur_dist) continue;

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i].first;
            int next_dist = cur_dist + edges[cur_node][i].second;
            if (dist[start][next_node] <= next_dist) continue;
            Node next_q = Node(next_node, next_dist, cur_path);
            dist[start][next_node] = next_dist;
            ans[start][next_node] = next_q.path;
            pq.push(next_q);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
    }
    for(int i=0;i<=V;i++)for(int j=0;j<=V;j++) if(i!=j) {
        dist[i][j] = INF;
    }
    for(int i=1;i<=V;i++) {
        dijktra(i);
    }

    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
        }
        cout << "\n"; 
    }
    for(int i=1;i<=V;i++) for(int j=1;j<=V;j++) {
        cout << ans[i][j].size() << " ";
        for (auto x : ans[i][j]) cout << x << " ";
        cout << "\n";
    }
}