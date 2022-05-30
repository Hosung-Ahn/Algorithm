# include <vector>
# include <queue>
using namespace std;

# define MAX 1001






int main() {
    int T; scanf("%d", &T);
    for (int t = 0; t < T; t++) { 

        vector<vector<int>> dist(MAX);
        int times[MAX] = {0,};
        int result[MAX] = {0,};
        int pre[MAX] = {0, };

        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &times[i]);

        for (int i = 0; i < m; i++) {
            int s, e; scanf("%d %d", &s, &e);
            dist[s].push_back(e);
            pre[e]++;
        }
        int goal; scanf("%d", &goal);

        queue<int> q;
        for (int start = 1; start <= n; start++) {
            if (pre[start] == 0) {
                q.push(start);
                result[start] = times[start];
            }
        }
        while (pre[goal] > 0) {
            int cur = q.front();
            q.pop();

            for (int next : dist[cur]) {
                result[next] = max(result[next], result[cur] + times[next]);
                if (--pre[next] == 0) q.push(next);
            }
        }

        printf("%d\n", result[goal]);
    }
}