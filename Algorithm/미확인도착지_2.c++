# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
# define MAX 2000+1
# define INF 987654321

vector<pair<int,int>> go[MAX];
vector<int> end_points;
int d[MAX];


int dijkstra(int s, int e) {
    for (int i = 0; i < MAX; i++)
        d[i] = INF;

    d[s] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,s});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (cur == e) {
            return cur_dist;
        }

        if(d[cur] < cur_dist) continue;

        for (int i = 0; i < go[cur].size(); i++) {
            int next = go[cur][i].first;
            int next_dist = cur_dist + go[cur][i].second;

            if (next_dist >= d[next]) continue;

            d[next] = next_dist;
            pq.push({-next_dist, next});
        }
    }

    return INF;
}


void clear() {
    for (int i = 0; i < MAX; i++) {
        go[i].clear();
    }
    end_points.clear();
}

void solution(int s, int g, int h, int d) {
    for (int end : end_points) {
        int tmp1 = dijkstra(s,g) + d + dijkstra(h,end);
        int tmp2 = dijkstra(s,h) + d + dijkstra(g,end);

        int total = dijkstra(s,end);

        if (total == tmp1 || total == tmp2) cout << end << " ";
    }
    cout << endl;
    clear();
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n,m,t; cin >> n >> m >> t;
        int s,g,h; cin >> s >> g >> h;

        int gh_d;

        for (int i = 0; i < m; i++) {
            int a,b,d; cin >> a >> b >> d;
            go[a].push_back({b,d});
            go[b].push_back({a,d});

            if ((a == g && b == h) || (b == g && a == h)) {
                gh_d = d;
            }
        }

        for (int i = 0; i < t; i++) {
            int e; cin >> e;
            end_points.push_back(e);
        }
        sort(end_points.begin(), end_points.end());

        solution(s,g,h,gh_d);
    }
}