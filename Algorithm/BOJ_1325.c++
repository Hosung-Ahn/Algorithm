#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int V,E;
#define MAX 10001
vector<int> edges[MAX];
vector<int> ans[MAX];
int maxCnt = 0;

int bfs(int start) {
    int ret = 0;
    queue<int> q;
    q.push(start);
    bool visited[MAX] = {0,};
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i];
            if (visited[next]) continue;
            visited[next] = true;
            ret++;
            q.push(next);
        }
    }
    return ret;
}

void solve() {
    for(int n=1;n<=V;n++) {
        int tmp = bfs(n);
        if(tmp > maxCnt) {
            maxCnt = tmp;
        }
        ans[tmp].push_back(n);
    }

    for(int n : ans[maxCnt]) {
        cout << n << " ";
    }
}

int main() {
    cin >> V >> E;
    for(int i=0;i<E;i++) {
        int a,b; cin >> a >> b;
        edges[b].push_back(a);
    }
    solve();
}