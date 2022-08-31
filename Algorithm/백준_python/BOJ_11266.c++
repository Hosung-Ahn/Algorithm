#include<iostream>
#include<vector>
using namespace std;
#define VMAX 10001

vector<int> edges[VMAX];
bool cutV[VMAX] = {0,};
int visited[VMAX] = {0,};
int V,E, cnt=0;

int dfs(int cur, bool root) {
    visited[cur] = ++cnt;
    int ret = visited[cur];
    int child = 0;

    for(int next : edges[cur]) {
        if (visited[next]) {
            ret = min(ret, visited[next]);
        }
        else {
            child++;
            int low = dfs(next, false);
            if(!root && low >= visited[cur]) cutV[cur] = true;
            ret = min(ret, low);
        }
    }
    
    if (root && child > 1) cutV[cur] = true;
    return ret;
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int s,e; cin >> s >> e; 
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    for(int v=1;v<=V;v++) {
        if (!visited[v]) dfs(v, true);
    }
    int ans=0;
    vector<int> arr;
    for(int v=1;v<=V;v++) if (cutV[v]){
        ans++;
        arr.push_back(v);
    }
    cout << ans << endl;
    for(int v : arr) cout << v << " ";
}