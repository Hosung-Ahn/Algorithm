# include <iostream> 
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 1001
int set[MAX] = {0,};

int get_parent(int a) {
    if (set[a] == a) return a;
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

class Edge {
public :
    int a,b,d;
    Edge(int a, int b, int d) : a(a), b(b), d(d) { }
};

bool cmp(Edge left, Edge right) {
    return left.d < right.d ;
}

int main() {
    for (int i = 1; i <= MAX; i++)
        set[i] = i;

    vector<Edge> edges;

    int N,M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a,b,d; scanf("%d %d %d", &a, &b, &d);
        edges.push_back(Edge(a,b,d));
    }

    sort(edges.begin(), edges.end(), cmp);

    int result = 0;

    for (Edge edge : edges) { 
        if (!find(edge.a, edge.b)) {
            union_node(edge.a, edge.b);
            result += edge.d;
        }
    }

    cout << result;
}