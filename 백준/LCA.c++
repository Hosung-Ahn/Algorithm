#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
# define MAX 100000+1
# define K 18

int N;
int depth[MAX] = {0,};
vector<vector<int>> edges(MAX, vector<int>());
bool visited[MAX] = {0,};
int parent[MAX][K] = {0,};

void dfs(int cur, int d) {
    visited[cur] = true;
    depth[cur] = d;

    for (int next : edges[cur]) {
        if (visited[next]) continue;
        parent[next][0] = cur;
        dfs(next, d+1);
    }
}

void connection() {
    for (int k = 1; k < K; k++) {
        for (int n = 1; n <= N; n++) {
            parent[n][k] = parent[parent[n][k-1]][k-1];
        }
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void solution(int a, int b) {
    if (a==b) {
        cout << a << "\n";
        return;
    }
    if (depth[a] < depth[b]) swap(a,b);

    if (depth[a] != depth[b]) {
        int diff = depth[a] - depth[b];

        int c = 0;
        while(diff) {
            if (diff % 2 == 1) a = parent[a][c];
            diff/=2;
            c++;
        }
    }

    if (a != b) {
        for (int k = K-1; k >= 0; k--) {
            if (parent[a][k] != parent[b][k]) {
                a = parent[a][k];
                b = parent[b][k];
            }
        }

        a = parent[a][0];
    }

    cout << a << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int s,e; cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    dfs(1,0);
    connection();

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        solution(a,b);
    }
}