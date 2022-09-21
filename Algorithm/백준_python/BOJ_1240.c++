#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define VMAX 1001
int N,M;
vector<int> edges[VMAX];
int dist[VMAX][VMAX] = {0,};

void bfs(int s) {
    bool visited[VMAX] = {0,};
    visited[s] = true;
    queue<pair<int,int>> q;
    q.push({s,0});

    while(!q.empty()) {
        int cur = q.front().first;
        int cur_d = q.front().second; 
        q.pop();

        for(int next : edges[cur]) {
            if (visited[next]) continue;
            int next_d = cur_d + dist[cur][next];
            dist[s][next] = next_d;
            q.push({next, next_d});
            visited[next] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N-1;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back(b);
        edges[b].push_back(a);
        dist[a][b] = d;
        dist[b][a] = d;
    }

    for(int n=1;n<=N;n++) {
        bfs(n);
    }

    for(int i=0;i<M;i++) {
        int s,e; cin >> s >> e;
        cout << dist[s][e] << "\n";
    }
}