#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 201

vector<int> edges[MAX];
int link[MAX] = {0,};
bool done[MAX] = {0,};
int N,M;

bool dfs(int cur) {
    for(int next : edges[cur]) {
        if (done[next]) continue;
        done[next] = true;
        if (link[next] == 0 || dfs(link[next])) {
            link[next] = cur;
            return true;
        }
    }
    return false;
}

void solve() {
    int ans = 0;
    for (int n=1;n<=N;n++) {
        memset(done, 0, sizeof(bool)*MAX);
        if (dfs(n)) ans++;
    }
    cout << ans;
}

int main() {
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        int k; cin >> k;
        for(int j=0;j<k;j++) {
            int x; cin >> x;
            edges[i].push_back(x);
        }
    }
    solve();
}