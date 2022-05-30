# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define MAX 501

int N,M;

vector<int> edges[MAX];
vector<int> edges_reverse[MAX];
int cnt[MAX] = {0,};
int cnt_reverse[MAX] = {0,};

void dfs(vector<bool> &visited, int cur, bool reverse = false) {
    visited[cur] = true;
    if (reverse) {
        cnt_reverse[cur]++;
        for (int next : edges_reverse[cur]) {
            if (visited[next]) continue;
            dfs(visited, next, true);
        }
    } 
    else {
        cnt[cur]++;
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            dfs(visited, next);
        }
    }
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges_reverse[e].push_back(s); 
    }

    for (int start = 1; start <= N; start++) {
        vector<bool>visited(MAX,0);
        vector<bool>visited2(MAX,0);
        dfs(visited, start);
        dfs(visited2, start,true);
    }

    int result = 0;

    for (int i = 1; i <= N; i++) {
        if (cnt[i] + cnt_reverse[i] == N+1)
            result++;
    }
    cout << result;
}