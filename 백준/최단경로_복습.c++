# include <iostream>
# include <queue>
# include <vector>

using namespace std;

# define INF 987654321
# define MAX 20001

int n;
vector<pair<int,int> > dist[MAX]; // start, dist, end
int result_d[MAX];

void dijkstra(int start) {
    result_d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (result_d[current] < distance) continue;

        for (int i = 0; i < dist[current].size(); i++){
            int next = dist[current][i].first;
            int next_dist = distance + dist[current][i].second;

            if (next_dist < result_d[next]) {
                result_d[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

void d_clear() {
    for (int i = 1; i <= n; i++) result_d[i] = INF;
}

int main() {
    int m, start;
    cin >> n >> m;
    cin >> start;
    int s,e,d;
    for (int i = 0; i<m; i++) {
        cin >> s >> e >> d;
        dist[s].push_back(make_pair(e,d));
    }

    d_clear();
    dijkstra(start);

    for (int i = 1; i<=n; i++) {
        if (result_d[i] == INF) cout << "INF\n";
        else cout << result_d[i] << "\n";
    }
}