#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define VMAX 101
 
vector<int> edges[VMAX];
int link[VMAX] = {0,};
bool done[VMAX] = {0,};
int N,M;

bool dfs(int cur) {
    for(int next : edges[cur]) {
        if (done[next]) continue;
        done[next] = true;
        if(link[next] == 0 || dfs(link[next])) {
            link[next] = cur;
            return true;
        }
    }
    return false;
}

void solve() {
    int ans = 0;
    for(int n=1;n<=N;n++) {
        memset(done, 0, sizeof(bool)*VMAX);
        if (dfs(n)) ans++;
    }
    cout << ans;
}

int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int s,e; cin >> s >> e;
        edges[s].push_back(e);
    }
    solve();
}