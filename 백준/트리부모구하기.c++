# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

using namespace std;

# define MAX 100001

vector<vector<int>> edge(MAX);
vector<int> parent_node(MAX);
bool visited[MAX] = {0, };

void find_parent_node(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) { 
        int cur =  q.front();
        q.pop();
        for (auto next : edge[cur]) {
            if (!visited[next]) {
                parent_node[next] = cur;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;

    for (int i = 0; i < n-1; i++) {
        int s,e; cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    find_parent_node(1);

    for (int node = 2; node <= n; node++) { 
        cout << parent_node[node] << "\n";
    }



}