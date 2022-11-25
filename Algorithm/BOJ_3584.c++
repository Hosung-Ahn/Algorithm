#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10001
int N;
int ac[MAX][20] = {0,};
int depth[MAX] = {0,};
vector<int> edges[MAX];

void find_ac_depth(int cur, int parent) {
    depth[cur] = depth[parent]+1;
    ac[cur][0] = parent;

    for(int i=1;i<=15;i++) {
        ac[cur][i] = ac[ac[cur][i-1]][i-1];
    }

    for(auto next : edges[cur]) find_ac_depth(next, cur);
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void match_depth(int &a, int &b) {
    if (depth[a] < depth[b]) swap(a,b);
    for(int i=15;i>=0;i--) {
        if (depth[ac[a][i]] >= depth[b]) a = ac[a][i];
    }
}

int find_coac(int a, int b) {
    for(int i=15;i>=0;i--) {
        if (ac[a][i] != ac[b][i]) {
            a = ac[a][i];
            b = ac[b][i];
        }
    }
    return a == b ? a : ac[a][0];
}

void clear() {
    memset(ac, 0, sizeof(ac));
    memset(depth, 0, sizeof(depth));
    for(int i=0;i<MAX;i++) edges[i].clear();
}

void solve() {
    int N; cin >> N;
    bool has_root[MAX] = {0,};
    for(int i=0;i<N-1;i++) {
        int p,c; cin >> p >> c;
        edges[p].push_back(c);
        has_root[c] = true;
    }
    int root;
    for(int n=1;n<=N;n++) if(!has_root[n]) root = n;
    find_ac_depth(root, 0);
    int a,b; cin >> a >> b;
    match_depth(a,b);
    cout << find_coac(a,b) << "\n";
    clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}