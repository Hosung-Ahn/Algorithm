# include <iostream>
# include <vector>
# include <queue>
using namespace std;
# define MAX 1001
# define INF 9876543210

int N;
vector<pair<int,int>> edge[MAX]; // start, end, cost
int dist[MAX];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (int i = 0; i < edge[cur_node].size(); i++) {
            int next_node = edge[cur_node][i].first;
            int next_dist = cur_dist + edge[cur_node][i].second;
            if (next_dist < dist[next_node]) { 
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main() {
    int M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e,c; scanf("%d %d %d", &s, &e, &c);
        edge[s].push_back({e,c});
    }

    for (int i = 0; i < MAX; i++)
        dist[i] = MAX;

    


}