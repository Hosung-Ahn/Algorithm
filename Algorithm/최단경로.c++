# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

# define INF 987654321
# define MAX 20001
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int m, start;
    cin >> n >> m;
    cin >> start;
    for (int i = 0; i < m; i++){
        int start, end, dist;
        cin >> start >> end >> dist;
        go[start].push_back(make_pair(dist, end));
    }
    
    d_clear();
    dijkstra(start);

    for (int i = 1; i<= n; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}