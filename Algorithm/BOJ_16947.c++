#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 3001
bool cycle[MAX] = {0,};
bool visited[MAX] = {0,};
vector<int> edges[MAX];
int N;

bool is_cycle(int cur, int parent, int start) {
    if (cur == start && parent != -1) return true;
    if (visited[cur]) return false;
    visited[cur] = true;
    for (int next : edges[cur]) {
        if (next == parent) continue;
        if (is_cycle(next, cur, start)) return true;
    }
    return false;
}

int bfs(int start) {
    int dist[MAX];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int cur = q.front(); 
        q.pop();

        if (cycle[cur]) return dist[cur];

        for (int next : edges[cur]) {
            if (dist[next] >= 0) continue;
            dist[next] = dist[cur]+1;
            q.push(next);
        }
    }
    return -1;
}

void solve() {
    for (int n=1;n<=N;n++) {
        memset(visited, 0, sizeof(visited));
        if (is_cycle(n,-1,n)) cycle[n] = true;
    }

    for (int n=1;n<=N;n++) {
        cout << bfs(n) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    solve();
}