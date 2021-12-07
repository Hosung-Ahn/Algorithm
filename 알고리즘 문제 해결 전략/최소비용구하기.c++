# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

using namespace std;
# define MAX 1001
# define ll long long
# define INF 1000000000000

int n; // 노드의 개수
vector<pair<int, ll> > dist[MAX]; // dist[start][i] = (end, dist)
ll d[MAX];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<ll,int> > pq; // (dist, start)
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;
        ll distance = -pq.top().first;
        pq.pop();

        if (d[current] < distance) continue; // 방문 여부 확인

        for (int i = 0; i < dist[current].size(); i++) {
            int next = dist[current][i].first;
            ll next_dist = distance + dist[current][i].second;

            if (next_dist < d[next]) {
                d[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

void d_clear() {
    for (int i = 1; i <= n; i++) d[i] = INF;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m,start,end;
    ll cost;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        dist[start].push_back(make_pair(end, cost));
    }
    cin >> start >> end;

    d_clear();
    dijkstra(start);

    cout << d[end] << endl;
}