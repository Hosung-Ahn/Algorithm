# include <iostream>
# include <vector>
using namespace std;

# define MAX 101
# define INF 1000000000

int n;

vector<vector<int>> dist(MAX, vector<int>(MAX, INF));

void floyd() {
    
    for (int bridge = 1; bridge <= n; bridge++) {
        for (int start = 1; start <= n; start++) {
            if (start == bridge) continue;
            for (int end = 1; end <= n; end++) { 
                if (end == bridge || start == end) continue;
                dist[start][end] = min(dist[start][end],
                                       dist[start][bridge] + dist[bridge][end]);
            }
        }
    }
}

int main() { 
    int m;
    cin >> n;
    cin >> m;

    int s,e,d;
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> d;
        dist[s][e] = min(dist[s][e], d);
    }

    floyd();

    for (int start = 1; start <= n; start++) {
        for (int end = 1; end <= n; end++) {
            if (dist[start][end] == INF) cout << 0 << " ";
            else cout << dist[start][end] << " ";
        }
        cout << "\n";
    }


}