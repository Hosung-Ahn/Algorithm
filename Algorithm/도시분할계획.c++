# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 100001

int set[MAX] = {0,};
int N,M;

class Edge {
public:
    int a,b,d;
    Edge(int a, int b, int d) : a(a), b(b), d(d) {}
};

int get_parent(int a) {
    if (a == set[a]) return a;
    return set[a] = get_parent(set[a]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

bool find(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) return true;
    return false;
}

bool cmp(Edge a, Edge b) {
    return a.d < b.d;
}

int main() {
    vector<Edge> edges;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a,b,d; scanf("%d %d %d", &a, &b, &d);
        edges.push_back(Edge(a,b,d));
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i < MAX; i++) {
        set[i] = i;
    }

    int result = 0;
    int max_dist = 0;

    for (Edge edge : edges) {
        if (!find(edge.a, edge.b)) {
            union_node(edge.a, edge.b);
            result += edge.d;
            max_dist = max(max_dist, edge.d);
        }
    }

    result -= max_dist;

    cout << result;
}