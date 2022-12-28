#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 300001
vector<int> edges[MAX];
vector<int> ans;
int dist[MAX];
int V,E,K,X;

void bfs() {
    dist[X] = 0;
    queue<int> q;
    q.push(X);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (dist[cur] == K) ans.push_back(cur);

        for(int next : edges[cur]) {
            if (dist[next] >= 0) continue;
            dist[next] = dist[cur]+1;
            q.push(next);
        }
    }
}

void solve() {
    bfs();
    sort(ans.begin(), ans.end());
    if (ans.empty()) cout << -1;
    else {
        for(int x : ans) cout << x << "\n";
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
    cin >> V >> E >> K >> X;
    for(int i=0;i<E;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
    }

    solve();
}