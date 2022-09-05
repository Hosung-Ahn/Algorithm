#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
    int p,d;
    Node(int p, int d) : p(p), d(d) {}
};

bool compare(const Node &a, const Node &b) {
    return a.d < b.d;
}

int main() {
    int N; cin >> N;
    vector<Node> arr;
    for(int i=0;i<N;i++) {
        int q,d; cin >> q >> d;
        arr.push_back(Node(q,d));
    }
    sort(arr.begin(), arr.end(), compare);

    priority_queue<int> pq;
    int ans = 0;
    for(Node node : arr) {
        if (pq.size() < node.d) {
            pq.push(-node.p);
            ans += node.p;
        }
        else {
            if (-pq.top() < node.p) {
                ans -= -pq.top();
                pq.pop();
                pq.push(-node.p);
                ans += node.p;
            }
        }
    }
    cout << ans;
}