# include <iostream>
# include <vector>
using namespace std;

# define MAX 2000
bool visited[MAX] = {0,};
vector<int> edges[MAX];
int result = 0;

void dfs(int cur, int cnt) {
    if (result) return;
    
    visited[cur] = true;
    if (cnt >= 5 ) {
        result = 1;
        visited[cur] = false;
        return;
    }

    for (int next : edges[cur]) {
        if (visited[next]) continue;
        dfs(next, cnt+1);
    }
    visited[cur] = false;
}

int main() { 
    int N,K; cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    for (int start = 0; start < N; start++) {
        dfs(start,1);
    }

    cout << result;

}