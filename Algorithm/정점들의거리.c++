# include <iostream>
# include <vector>
using namespace std;

# define MAX 40001
# define MAX_DEPTH 20

vector<pair<int,int>> edges[MAX];
int N;
int d[MAX] = {0,};
bool visited[MAX] = {0,};

int depth[MAX] = {0,};
int tree[MAX][20] = {0,};

void get_tree(int cur, int parent) {
    depth[cur] = depth[parent] + 1;
    tree[cur][0] = parent;

    for (int i = 1; i < MAX_DEPTH; i++) {
        int tmp = tree[cur][i-1];
        tree[cur][i] = tree[tmp][i-1];
    }

    for (pair<int,int> next : edges[cur]) {
        int next_node = next.first;
        if (next_node == parent) continue;

        get_tree(next_node, cur);
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int get_lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a,b);

    for (int i = MAX_DEPTH-1; i >= 0; i--) {
        if (depth[a] <= depth[tree[b][i]]) {
            b = tree[b][i];
        }
    }

    int lca = a;

    if (a != b) {
        for (int i = MAX_DEPTH-1; i >= 0; i--) {
            if (tree[a][i] != tree[b][i]) {
                a = tree[a][i];
                b = tree[b][i];
            }
            lca = tree[a][i];
        }
    }
    return lca;
}


void find_d(int cur, int cost) {
    visited[cur] = true;
    d[cur] = cost;

    for (pair<int,int> next : edges[cur]) {
        int next_node = next.first;
        int next_cost = next.second;
        if (visited[next_node]) continue;
        find_d(next_node, cost + next_cost);
    }
    visited[cur] = false;
}



int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int s,e,c; scanf("%d %d %d", &s, &e, &c);
        edges[s].push_back({e,c});
        edges[e].push_back({s,c});
    }

    find_d(1,0);

    depth[0] = -1;
    get_tree(1,0);

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int a,b; scanf("%d %d", &a, &b);
        int lca = get_lca(a,b);

        cout << d[a] + d[b] - d[lca]*2 << "\n";
    }
}

