#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 101
vector<int> edges[MAX];
int N,S,E;

void bfs(int start) {
    queue<pair<int,int>> q;
    bool visited[MAX] = {0,};
    visited[start] = true;
    q.push({start,0});
    
    while(!q.empty()) {
        int cur_node = q.front().first;
        int cur_dist = q.front().second;
        q.pop();

        if(cur_node == E) {
            cout << cur_dist;
            return;
        }

        for(int i=0;i<edges[cur_node].size();i++) {
            int next_node = edges[cur_node][i];
            if (visited[next_node]) continue;
            visited[next_node] = true;
            q.push({next_node, cur_dist+1});
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> S >> E;
    int e; cin >> e;
    for(int i=0;i<e;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bfs(S);
}