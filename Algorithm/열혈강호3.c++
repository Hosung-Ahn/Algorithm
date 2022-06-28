#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1000

int N,M,K;
vector<int> aMatch, bMatch;
vector<int> edges[MAX];
vector<bool> visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (int b : edges[a]) {
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
    }
    int cnt = 0;
    for (int start = 0; start < N; start++) {
        visited = vector<bool>(N, false);
        if (dfs(start) && cnt < K) {
            size++;
            cnt++;
        }
    }
    return size;
}

int main() {
    cin >> N >> M >> K;
    for (int a = 0; a < N; a++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int b; cin >> b;
            edges[a].push_back(b-1);
        }
    }
    cout << bipartiteMatch();
}