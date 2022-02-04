# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 10001

vector<vector<pair<int,int>>> edges(MAX);
int N, M;

bool bfs(int start, int end, int cost) {
    bool visited[MAX] = {0,};
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) return true;

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            int next_cost = edges[cur][i].second;

            if (visited[next] || next_cost < cost) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}

int binary_search(int start, int end, int max_cost) {
    int low = 1;
    int high = max_cost;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (bfs(start, end, mid)) low = mid + 1;
        else high = mid - 1;
    }

    return high;
}

int main() {
    cin >> N >> M;

    int max_cost = 0; 
    for (int i = 0; i < M; i++) {
        int s,e,c; scanf("%d %d %d", &s, &e, &c);
        edges[s].push_back({e,c});
        edges[e].push_back({s,c});
        max_cost = max(max_cost, c);
    }

    int start, end; scanf("%d %d", &start, &end);

    cout << binary_search(start, end, max_cost);
}