#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 501

vector<int> edges[MAX];
bool visited[MAX] = {0,};
bool cycle = false;
int N,M;
int num = 1;

void dfs(int cur, int parent) {
    for (int next : edges[cur]) {
        if (next == parent) continue;
        if (visited[next]) {
            cycle = true;
            continue;
        }
        visited[next] = true;
        dfs(next, cur);
    }
}

void clear() {
    memset(visited, 0, sizeof(bool)*MAX);
    for(int i=0;i<MAX;i++) edges[i].clear();
}

void input() {
    for(int i=0;i<M;i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
}

bool solve() {
    clear();
    cin >> N >> M;
    if (N==0 && M==0) return false;
    input();
    int ans = 0;
    for(int i=1;i<=N;i++) {
        if (visited[i]) continue;
        cycle = false;
        dfs(i,-1);
        if (!cycle) ans++;
    }
    cout << "Case " << num++ << ": ";
    if (ans == 0) {
        cout << "No trees.\n";
    }
    else if (ans == 1) {
        cout << "There is one tree.\n";
    }
    else {
        cout << "A forest of " << ans << " trees.\n";
    }
    return true;
}

int main(){
    while(solve()) {
        
    }
}