#include <iostream>
#include <limits>

using namespace std;
# define MAX 400+1
const int INF = INT32_MAX/2;

int V,E;
int dist[MAX][MAX];

void floyd() {
    for (int m = 1; m <= V; m++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
            }
        }
    }
}

void solution() {
    int result = INF;
    for (int i = 1; i <= V; i++) {
        result = min(result, dist[i][i]);
    }
    result == INF ? cout << -1 : cout << result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = INF;
        }
    }

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s,e,d; cin >> s >> e >> d;
        dist[s][e] = d;
    }

    floyd();
    solution();

}