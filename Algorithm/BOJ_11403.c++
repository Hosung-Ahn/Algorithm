#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
int N;
bool edge[MAX][MAX] = {0,};
bool connect[MAX][MAX] = {0,};

void bfs(int start) {
    queue<int> q;
    bool visited[MAX] = {0,};
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next=0;next<N;next++) {
            if(!edge[cur][next] || visited[next]) continue;
            visited[next] = true;
            connect[start][next] = true;
            q.push(next);
        }
    }
}

void solve() {
    for(int n=0;n<N;n++) {
        bfs(n);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << connect[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        cin >> edge[i][j];
    }
    solve();
}