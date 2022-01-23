# include <iostream>
# include <queue>
# include <vector> 
using namespace std;

# define MAX 1001
# define INF 987654321

vector<vector<pair<int,int>>> go(MAX);
vector<int> result;
int dist[MAX];
int set[MAX];

void dijkstra(int s, int e) {
    dist[s] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, s});


    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (dist[cur] < cur_dist) continue;

        for (int i = 0; i < go[cur].size(); i++) {
            int next = go[cur][i].first;
            int next_dist = cur_dist + go[cur][i].second;

            if (dist[next] <= next_dist) continue;
            dist[next] = next_dist;
            set[next] = cur;
            pq.push({-next_dist, next});
        }
    }
}

void find_path(int s, int e) {
    result.push_back(e);
    if (e == s) return;
    find_path(s,set[e]);
}

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e,d; scanf("%d %d %d", &s, &e, &d);
        go[s].push_back({e,d});
    }
    int start, end; cin >> start >> end;

    for (int i = 0; i < MAX; i++)
        dist[i] = INF;

    dijkstra(start, end);
    cout << dist[end] << endl;

    find_path(start, end);
    
    vector<int>::reverse_iterator iter;
    cout << result.size() << endl;
    
    for(iter = result.rbegin(); iter != result.rend(); iter++) {
        cout << *iter << " ";
    }

}