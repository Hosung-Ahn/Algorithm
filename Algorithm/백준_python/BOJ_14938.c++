#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
#define INF 987654321
int arr[MAX] = {0,};
vector<pair<int,int>> edges[MAX];
int N,M,R;

int dijkstra(int start) {
    int dist[MAX];
    for (int i=0;i<MAX;i++) dist[i] = INF;
    dist[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_d = -pq.top().first;
        pq.pop();

        if (dist[cur] < cur_d) continue;

        for (int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            int next_d = cur_d + edges[cur][i].second;
            if (dist[next] <= next_d) continue;
            dist[next] = next_d;
            pq.push({-next_d, next});
        }
    }

    int ret = 0;
    for(int n=1;n<=N;n++) if (dist[n] <= R){
        ret += arr[n];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> R >> M;
    for(int i=1;i<=N;i++) cin >> arr[i];

    for(int i=0;i<M;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
    }

    int ans = 0;
    for(int s=1;s<=N;s++) {
        ans = max(ans, dijkstra(s));
    }
    cout << ans;
}