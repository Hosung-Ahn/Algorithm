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
    Edge(int s, int e, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator < (Edge &edge) {
        return this->distance < edge.distance;
    }
};



