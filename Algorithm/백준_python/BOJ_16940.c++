#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

vector<int> edges[MAX];
vector<int> ans;
int visited[MAX] = {0,};
int N; 

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int cur = q.front(); 
        ans.push_back(visited[cur]);
        q.pop();

        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = visited[cur]+1;
            q.push(next);
        }
    }
}

void solve() {
    bfs();
    vector<int> arr(N, 0);
    for(int i=0;i<N;i++) {
        int a; cin >> a;
        if (ans[i] != visited[a]) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main() {
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int s,e; cin >> s >> e;
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    solve();
}