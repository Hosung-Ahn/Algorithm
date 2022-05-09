# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>
using namespace std;
# define MAX 2000+1
# define INF 987654321

int dist[MAX][MAX];
bool is_passed[MAX][MAX] = {0,};
vector<int> end_points;

void floyd(int n, int s ) {
    for (int bridge = 1; bridge <= n; bridge++) {
        int start = s;
        if (start == bridge) continue;
        for (int end = 1; end <= n; end++) {
            if (end == bridge || end == start) continue;

            if (dist[start][end] > dist[start][bridge] + dist[bridge][end]) {
                dist[start][end] = dist[start][bridge] + dist[bridge][end];
                if (is_passed[start][bridge] || is_passed[bridge][end]) {
                    is_passed[start][end] = true;
                }
            }
        }
        
    }
}

void clear() {
    for (int i = 0; i < MAX; i++) {
        memset(is_passed[i], 0, sizeof(bool)*MAX);
    }
    end_points.clear();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        int n,m,t;
        int s,g,h;
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        is_passed[g][h] = true;
        is_passed[h][g] = true;

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                dist[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            int a,b,d; cin >> a >> b >> d;
            dist[a][b] = d;
            dist[b][a] = d;
        }
        for (int i = 0; i < t; i++) {
            int x; cin >> x;
            end_points.push_back(x);
        }
        sort(end_points.begin(), end_points.end());

        floyd(n,s);
        
        for (int end : end_points) {
            if(is_passed[s][end]) cout << end << " ";
        }
        cout << endl;
        clear();
    }
}