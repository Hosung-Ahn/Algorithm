# include <iostream> 
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 20001

vector<int> edges[MAX];
int color[MAX];
int V,E;

void bfs(int start) {
    color[start] = 1;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : edges[cur]) {
            if (color[next] != -1) continue;
            color[next] = (color[cur] + 1) % 2;
            q.push(next);
        }
    }
}

bool is_bipartite() {
    for (int cur = 1; cur <= V; cur++) {
        for (int next : edges[cur]) {
            if (color[cur] == color[next]) return false;
        }
    }
    return true;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> V >> E;
        memset(color, -1, sizeof(int)*MAX);
        for (int i = 0; i < E; i++) {
            int a,b; scanf("%d %d", &a, &b);
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for (int i = 1; i <= V; i++) {
            if (color[i] == -1) bfs(i);
        }
        if (is_bipartite()) cout << "YES\n";
        else cout << "NO\n";

        for (int i = 1; i <= V; i++) 
            edges[i].clear();
    }


}