# include <iostream>
# include <vector>
# include <string.h>
# include <algorithm>
using namespace std;

# define MAX 10001
int V,E; 
vector<int> edges[MAX];
vector<int> edges_reversed[MAX];
vector<int> stack;

bool visited[MAX] = {0,};
vector<vector<int>> scc_arr;

void dfs(int cur) {
    visited[cur] = true;
    for (int next : edges[cur]) {
        if (visited[next]) continue;
        dfs(next);
    }
    stack.push_back(cur);
}

void find_scc(int cur, vector<int> &scc) {
    visited[cur] = true;
    scc.push_back(cur);
    for (int next : edges_reversed[cur]) {
        if (visited[next]) continue; 
        find_scc(next, scc);
    }
}

bool cmp(const vector<int> &left, const vector<int> &right) {
    return left[0] < right[0];
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges_reversed[e].push_back(s);
    }

    for (int n = 1; n <= V; n++) {
        if (visited[n]) continue;
        dfs(n);
    }

    memset(visited, 0, sizeof(bool)*MAX);

    while (!stack.empty()) {
        int cur = stack.back();
        stack.pop_back();
        if (visited[cur]) continue;
        vector<int> scc;
        find_scc(cur, scc);
        sort(scc.begin(), scc.end());
        scc_arr.push_back(scc);
    }

    sort(scc_arr.begin(), scc_arr.end(), cmp);

    cout << scc_arr.size() << "\n";
    for (vector<int> scc : scc_arr) {
        for (int n : scc) {
            cout << n << " ";
        }
        cout << "-1\n";
    }
}