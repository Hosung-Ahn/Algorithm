# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 32001

vector<int> edges[MAX];
int in_degree[MAX] = {0,};
int N,M;

void topology_sort() {

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int next : edges[cur]) {
            if (--in_degree[next] == 0) {
                pq.push(next);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        in_degree[e]++;
    }

    topology_sort();




}