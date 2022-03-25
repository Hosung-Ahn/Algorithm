# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 100000
int set[MAX] = {0,};

int find_parent(int a) {
    if (set[a] == a) return a;
    return set[a] = find_parent(set[a]);
}

void node_union(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

bool same_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return true;
    return false;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        set[i] = i;
    }

    vector<pair<int,int>> X,Y,Z;
    vector<pair<int, pair<int,int>>> edges;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y,z; scanf("%d %d %d", &x,&y,&z);
        X.push_back({x,i});
        Y.push_back({y,i});
        Z.push_back({z,i});
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 1; i < N; i++) {
        edges.push_back({X[i].first - X[i-1].first, {X[i].second, X[i-1].second}});
        edges.push_back({Y[i].first - Y[i-1].first, {Y[i].second, Y[i-1].second}});
        edges.push_back({Z[i].first - Z[i-1].first, {Z[i].second, Z[i-1].second}});
    }

    sort(edges.begin(), edges.end());

    int result = 0;

    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int dis = edges[i].first;

        if (same_set(a,b)) continue;
        node_union(a,b);
        result += dis;
    }

    cout << result << endl;
}