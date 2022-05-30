#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
#define ll long long

int Set[MAX];
struct Point {
    int x,y;
    Point(int x = 0, int y = 0) : x(x), y(y) { }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct Node {
    int a,b;
    long double d;
    Node(int a, int b, long double d) : a(a), b(b), d(d) { }
};

int getParent(int a) {
    if (a == Set[a]) return a;
    return Set[a] = getParent(Set[a]);
}

void unionNode(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) Set[a] = b;
    else Set[b] = a;
}

bool find(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    return a == b;
}

long double dist(const Point &a, const Point &b) {
    return sqrtl( (ll)(a.x-b.x)*(a.x-b.x) + (ll)(a.y-b.y)*(a.y-b.y) );
}

vector<Point> arr(MAX, Point());
vector<Node> edges;

bool cmp(const Node &a, const Node &b) {
    return a.d < b.d;
}

int main() {
    for (int i = 0; i < MAX; i++) {
        Set[i] = i;
    }

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int x,y; cin >> x >> y;
        arr[i].set(x,y);
    }

    for (int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        unionNode(a,b);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            edges.push_back(Node(i,j, dist(arr[i], arr[j])));
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    double result = 0;
    
    for (Node n : edges) {
        if (!find(n.a, n.b)) {
            unionNode(n.a, n.b);
            result += n.d;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result;
}

