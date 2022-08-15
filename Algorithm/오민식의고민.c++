#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

#define ll long long
#define MAX 50
#define INF 9223372036854775807

vector<int> cycle_node;

struct Node {
    int s,e;
    ll d;
    Node(int s, int e, ll d) : s(s), e(e), d(d) {}
};

vector<ll> dist(MAX,INF);
vector<Node> edges;
int coin[MAX];

int N,S,E,M;

bool bfs(int s) {
    bool visited[MAX] = {0,};
    visited[s] = true;
    queue<int> q;
    q.push(s);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == E) return true;

        for (auto node : edges) {
            if (node.s != cur) continue;
            int next = node.e;
            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
            
        }
    }

    return false;
}

void bellman_ford() {
    dist[S] = 0;
    bool cycle = false;

    for (int i=0;i<N;i++) {
        for (auto node : edges) {
            int s = node.s;
            int e = node.e; 
            ll d = node.d;

            if (dist[s] == INF || dist[e] <= dist[s]+d) continue;
            dist[e] = dist[s]+d;
            // 벨만포드 마지막 라운드에서 갱신되는 노드들은
            // 음의 사이클을 발생시키는 간선이 모두 포함되어 있다.
            if (i == N-1) {
                cycle = true;
                cycle_node.push_back(s);
            }
        }
    }

    if (dist[E] == INF) {
        cout << "gg";
    }
    else if (cycle) {
        ll cur_d = dist[E];
        for (auto s : cycle_node) {
            if (bfs(s)) {
                cout << "Gee";
                return;
            }
        }
        cout << coin[S]-dist[E];
    }
    else {
        cout << coin[S]-dist[E];
    }
}

int main() {
    cin >> N >> S >> E >> M;
    for (int i=0;i<M;i++) {
        int s,e,d; cin >> s >> e >> d;
        edges.push_back(Node(s,e,d));
    }
    for (int i=0;i<N;i++) cin >> coin[i];
    for (Node &node : edges) {
        node.d -= coin[node.e];
    }
    bellman_ford();
}