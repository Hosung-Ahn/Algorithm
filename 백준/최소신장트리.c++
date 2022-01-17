# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int get_parent(int set[], int x) {
    if (set[x] == x) return x;
    return set[x] = get_parent(set, set[x]);
}

void union_parent(int set[], int a, int b) {
    a = get_parent(set, a);
    b = get_parent(set, b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

// 두 정점이 같은 그래프에 있는지 확인
bool find(int set[], int a, int b) {
    a = get_parent(set, a);
    b = get_parent(set, b);
    
    if (a == b) return true;
    else return false;
}

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
};

bool cmp(const Edge &l, const Edge &r) {
    return l.distance < r.distance;
}

int main() {
    int V,E; cin >> V >> E;
    vector<Edge> edges;

    for (int i = 0; i < E; i++){
        int s,e,d; scanf("%d %d %d", &s, &e, &d);
        edges.push_back(Edge(s,e,d));
    }
    
    sort(edges.begin(), edges.end(), cmp);

    int set[V];
    for (int i = 0; i < V; i++)
        set[i] = i;

    int sum = 0;

    for (int i = 0; i < edges.size(); i++) {
        if (!find(set, edges[i].node[0] - 1, edges[i].node[1] -1)) {
            sum += edges[i].distance;
            union_parent(set, edges[i].node[0] - 1, edges[i].node[1] -1);
        }
    }

    cout << sum;
}

