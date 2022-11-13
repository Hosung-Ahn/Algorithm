#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
struct Node {
    int s,e,c;
    Node(int s, int e, int c) : s(s), e(e), c(c) {}
    bool operator<(const Node &other) const {
        if (e == other.e) {
            int p1 = e-s, p2 = other.e - other.s;
            return p1 < p2;
        }
        return e < other.e;
    }
};
vector<Node> arr;
int N,C,M;
int extras[2000];

int find_extra(int s, int e) {
    int ret = 987654321;
    for(int i=s;i<e;i++) {
        ret = min(ret, extras[i]);
    }
    return ret;
}

void load(int s, int e, int c) {
    for(int i=s;i<e;i++) extras[i]-=c;
}

void solve() {
    sort(arr.begin(), arr.end());
    for(int i=0;i<N;i++) extras[i] = C;

    int ans = 0;
    for(int i=0;i<M;i++) {
        int s = arr[i].s, e = arr[i].e, c = arr[i].c;
        int extra = min(find_extra(s,e), c);
        
        if (extra > 0) {
            load(s,e,extra);
            ans += extra;
        }
    }
    cout << ans;
}

int main() {
    cin >> N >> C >> M;
    
    for(int i=0;i<M;i++) {
        int s,e,c; cin >> s >> e >> c;
        arr.push_back(Node(s-1,e-1,c));
    }
    
    solve();
}