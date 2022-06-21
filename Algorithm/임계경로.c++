#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001

vector<pair<int,int>> edges[MAX], r_edges[MAX];
int in_degree[MAX] = {0,};
int N,M;
int dist[MAX] = {0,};

// 위상정렬을 사용하면 현재 노드까지의 길이들을 전부 구한다음에 다음 노드를 탐색하게 되므로
// 최장길이를 찾는 것이 보장된다.
void topology_sort(int start) {
    queue<int> q;
    q.push(start);

    // 위상정렬이 총 N개 의 vertex를 탐색하지 못한다면 cycle이 발생했는다는 것을 의미함.
    for (int i = 0; i < N; i++) {
        int cur = q.front();
        q.pop();

        for (auto X : edges[cur]) {
            int next = X.first;
            int next_dist = X.second + dist[cur];
            if (--in_degree[next] == 0) q.push(next);
            if (dist[next] < next_dist) dist[next] = next_dist;
        }
    }
}

int reverse_bfs(int end) {
    bool visited[MAX] = {0,};
    queue<int> q;
    q.push(end);
    int cnt = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto X : r_edges[cur]) {
            int next = X.first;
            int next_dist = dist[cur]-X.second;

            // cout << next << " " << next_dist << endl;
            if (next_dist != dist[next]) continue;
            cnt++;
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e,d; cin >> s >> e >> d;
        edges[s].push_back({e,d});
        r_edges[e].push_back({s,d});
        in_degree[e]++;
    }
    int start, end; cin >> start >> end;
    topology_sort(start);
    cout << dist[N] << "\n" << reverse_bfs(end);
}