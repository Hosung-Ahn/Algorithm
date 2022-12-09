#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321
#define MAX 101
struct Node {
    int a,b,d;
    Node(int a, int b, int d) : a(a), b(b), d(d) {}
};
vector<Node> edges;
vector<int> goes[MAX];
int V,E;
int dist[MAX];
int from[MAX] = {0,};

bool bfs(int start) {
    bool visited[MAX] = {0,};
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == V) return true;
        for(int next : goes[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
    return false;
}

bool bellman() {
    dist[1] = 0;
    for(int n=1;n<=V;n++) {
        for(auto edge : edges) {
            int a = edge.a;
            int b = edge.b;
            int d = edge.d;
            if (dist[a] != INF && dist[b] < dist[a]+d) {
                if (n == V && bfs(a)) return false;
                dist[b] = dist[a]+d;
                from[b] = a;
            }
        }
    }
    return true;
}

void find_path() {
    vector<int> arr;
    int cur = V;
    while (cur != 0) {
        arr.push_back(cur);
        cur = from[cur];
    }
    reverse(arr.begin(), arr.end());
    for(auto a : arr) cout << a << " ";
}

void solve() {
    if (!bellman() || dist[V] == -INF) {
        cout << -1;
        return;
    }
    find_path();
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges.push_back(Node(a,b,d));
        goes[a].push_back(b);
    }
    for(int i=0;i<MAX;i++) dist[i]=-INF;
    solve();
}