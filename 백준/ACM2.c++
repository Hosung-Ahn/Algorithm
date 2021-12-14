# include <iostream>
# include <vector>
# include <queue>
# include <cstring>
# include <cstdio>
using namespace std;

# define MAX 1001

int times[MAX] = {0,};
int path[MAX] = {0,};
int total_times[MAX] = {0,};

int bfs(int start, const vector<vector<int>> &dist) {
    queue<int> q;
    q.push(start);
    path[start] = 0;

    int i;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        i = path[cur];
        if (times[cur] > total_times[i]) total_times[i] = times[cur];

        for (int next : dist[cur]) {
            q.push(next);
            path[next] = path[cur] + 1;
        }
    }

    return i; 
}

void all_clear() {
    for (int i = 0; i < MAX; i++) {
        times[i] = 0;
        path[i] = 0;
        total_times[i] = 0;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    int n,m,x,s,e,goal,last_index, result;

    for (int t = 0; t < T; t++) { 
        cin >> n >> m;
        vector<vector<int>> dist(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> x;
            times[i] = x;
        }

        for (int i = 0; i < m; i++) { 
            cin >> s >> e;
            dist[e].push_back(s);
        }
        cin >> goal;

        last_index = bfs(goal, dist);

        result = 0;
        for (int i = 0; i <= last_index; i++) {
            result += total_times[i];
        }
        cout << result << endl;

        all_clear();
    }

}