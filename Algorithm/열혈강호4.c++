#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 1000

int N,M,K;
vector<int> aMatch, bMatch;
vector<int> edges[MAX];
bool visited[MAX] = {0,};

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
        memset(visited, 0, sizeof(bool)*MAX);
        if (dfs(start)) size++;
    }

    int cnt = 0;
    bool full = false;
    while(cnt < K && !full) {
        full = true;
        for (int start = 0; start < N; start++) {
            memset(visited, 0, sizeof(bool)*MAX);
            if (dfs(start)) {
                full = false;
                size++;
                cnt++;
                break;
            }
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