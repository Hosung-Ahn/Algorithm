#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 3001
bool cycle[MAX] = {0,};
int N;
vector<int> edges[MAX];

int bfs(int start) {
    int visited[MAX] = {0,};
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        int cur = q.front(); 
        q.pop(); 

        if (cycle[cur]) return visited[cur];

        for (int next : edges[cur]) {
            if (visited[next] >= 0) continue;
            visited[next] = visited[cur]+1;
            q.push(next);
        }
    }
    return -1;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}