#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int dl, x;
    Node(int dl, int x) : dl(dl), x(x) {}
};
vector<Node> arr;

bool cmp(const Node &a, const Node &b) {
    return a.dl < b.dl;
}

void solve() {
    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int> pq;
    for(Node node : arr) {
        if (pq.size() < node.dl) {
            pq.push(-node.x);
        }
        else {
            int tx = -pq.top(); 
            if (tx < node.x) {
                pq.pop();
                pq.push(-node.x);
            }
        }
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += -pq.top();
        pq.pop();
    }

    cout << ans;
}

int main() {
    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int dl,x; cin >> dl >> x;
        arr.push_back(Node(dl,x));
    }   
    solve();
}