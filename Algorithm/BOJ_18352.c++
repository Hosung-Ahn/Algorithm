#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 300001
int V,E,K,X;
vector<int> edges[MAX];
vector<int> ans;

struct Node {
    int a,d;
    Node(int a, int d) : a(a), d(d) {}
};

void bfs() {
    bool visited[MAX] = {0,};
    queue<Node> q;
    q.push(Node(X,0));
    visited[X] = true;
    while(!q.empty()) {
        int cur = q.front().a;
        int cur_dist = q.front().d;
        q.pop();

        if (cur_dist == K) ans.push_back(cur);

        for(int next : edges[cur]) {
            if(visited[next]) continue;
            visited[next] = true;
            q.push(Node(next, cur_dist+1));
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
    cin >> V >> E >> K >> X;
    for(int i=0;i<E;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
    }
    solve();
}