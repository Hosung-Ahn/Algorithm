# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

# define INF 987654321
# define MAX 801
using namespace std;

int n;
vector<pair<int,int> > go[MAX]; // start, dist, end 
int d[MAX];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (d[current] < distance) continue; // 방문 여부 대체
        
        
        int size = go[current].size();
        for (int i = 0; i < size; i++) {
            int next = go[current][i].second;
            int next_distance = distance + go[current][i].first;
            if (next_distance < d[next]) {
                d[next] = next_distance;
                pq.push(make_pair(-next_distance, next));
            }
        } 
    }
}

void d_clear() {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }
}

int dist_from_to(int from, int to, bool& vaild) {
    d_clear();
    dijkstra(from);
    if (d[to] == INF) vaild = false; 
    return d[to];
}

void total_dist(int first, int second, int& result, bool& vaild) { 
    result += dist_from_to(1, first, vaild);
    result += dist_from_to(first, second, vaild);
    result += dist_from_to(second, n, vaild);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m, v1, v2;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int start, end, dist;
        cin >> start >> end >> dist;
        go[start].push_back(make_pair(dist, end));
        go[end].push_back(make_pair(dist, start));
    }
    cin >> v1 >> v2;
    
    int dist_v1_to_v2 = 0, dist_v2_to_v1 = 0;
    
    bool v12 = true, v21 = true; 
    total_dist(v1,v2, dist_v1_to_v2, v12);
    total_dist(v2,v1, dist_v2_to_v1, v21);

    if (v12 && v21) cout << min(dist_v1_to_v2, dist_v2_to_v1) << endl;
    else if (v12) cout << dist_v1_to_v2 << endl;
    else if (v21) cout << dist_v2_to_v1 << endl;
    else cout << -1 << endl;
}