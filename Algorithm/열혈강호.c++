#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1000

int N,M;
bool adj[MAX][MAX] = {0,};
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (int b = 0; b < M; b++) {
        if (!adj[a][b]) continue;

        if (bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    aMatch = vector<int>(N,-1);
    bMatch = vector<int>(M,-1);
    int size = 0;
    for (int start = 0; start < N; start++) {
        visited = vector<bool>(N, false);
        if (dfs(start)) size++;
        visited = vector<bool>(N, false);
        if (dfs(start)) size++;
    }
    return size;
}

int main() {
    cin >> N >> M;
    for (int a = 0; a < N; a++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int b; cin >> b;
            adj[a][b-1] = true;
        }
    }
    cout << bipartiteMatch();
}