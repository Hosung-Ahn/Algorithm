#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int width, idx;
    Node(int width, int idx) : width(width), idx(idx) {}
    bool operator<(const Node &other) const {
        if (width == other.width) {
            return idx < other.idx;
        }
        return width > other.width;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    priority_queue<Node> pq;
    int D,N; cin >> D >> N;
    for(int i=1;i<=D;i++) {
        int w; cin >> w;
        pq.push(Node(w,i));
    }
    int idx = D+1;
    for(int i=0;i<N;i++) {
        int n; cin >> n;
        while(1) {
            if (pq.top().idx > idx) {
                pq.pop();
            }
            else if (pq.top().width < n) {
                idx = pq.top().idx;
                pq.pop();
            }
            else break;
        }
        idx-=1;
    }
    cout << idx;
}