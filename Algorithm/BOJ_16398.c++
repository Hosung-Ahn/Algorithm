#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
int set[MAX];

struct Node {
    int a,b,d;
    Node(int a, int b, int d) : a(a), b(b), d(d) {}
    
    bool operator<(const Node &other) const {
        return d < other.d;
    }
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

bool is_set(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a == b;
}

int main() {
    int N; cin >> N;
    vector<Node> arr;
    for(int a=1;a<=N;a++) for(int b=1;b<=N;b++) {
        int d; cin >> d;
        arr.push_back(Node(a,b,d));
    }
    sort(arr.begin(), arr.end());

    for(int n=1;n<=N;n++) set[n]=n;

    int ans = 0;

    for (Node node : arr) {
        int a = node.a;
        int b = node.b;
        int d = node.d;
        if (is_set(a,b)) continue;
        union_node(a,b);
        ans += d;
    }
    cout << ans;
}