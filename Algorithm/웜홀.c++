# include <iostream>
# include <vector>
# include <queue>
# include <cstdio>

using namespace std;

# define MAX 501
# define INF 987654321

int n;
int d[MAX];
vector<pair<int,int> > dist[MAX]; // dist[start][index] = (end, dist) 

void d_clear() {
    for (int i = 1; i <= n; i++) d[i] = INF;
}

void dist_clear() {
    for (int i = 1; i <= n; i++) dist[i].clear();
}

void bellman_ford(bool& cycle) {

    for (int cnt = 1; cnt <= n; cnt++) {
        for (int start = 1; start <= n; start++) {
            for (int i = 0; i < dist[start].size(); i++) {
                int end = dist[start][i].first;
                int to_end_dist = d[start] + dist[start][i].second;
                if (to_end_dist < d[end]) {
                    d[end] = to_end_dist;
                    if (cnt == n) cycle = true;
                }
            }
        }
    }
}

void is_time_back() {
    d_clear();
    bool cycle = false;
    bellman_ford(cycle);
    if (cycle) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T, m, w; cin >> T;
    int start, end, cost;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++) {
            cin >> start >> end >> cost;
            dist[start].push_back(make_pair(end, cost));
            dist[end].push_back(make_pair(start, cost));
        }
        for (int i = 0; i < w; i++) {
            cin >> start >> end >> cost;
            dist[start].push_back(make_pair(end, -cost));
        }

        d_clear();
        is_time_back();
        dist_clear();


    }
}