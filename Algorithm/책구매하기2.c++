#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 210
#define INF 987654321

int c[MAX][MAX] = {0,}, f[MAX][MAX] = {0,};

void networkflow(int s, int e) {
    int totalFlow = 0;
    while(1) {
        vector<int> parent(MAX, -1);
        parent[s] = s;
        queue<int> q; q.push(s);

        while(!q.empty() && parent[e] == -1) {
            int cur = q.front(); q.pop();
            for(int next = 0; next < MAX; next++) {
                if(c[cur][next] - f[cur][next] > 0 && parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }

        if (parent[e] == -1) break;
        
        int flow = INF;
        for (int p = e; p != s; p = parent[p]) {
            flow = min(flow , c[parent[p]][p] - f[parent[p]][p]);
        }
        for (int p = e; p != s; p = parent[p]) {
            f[parent[p]][p] += flow;
            f[p][parent[p]] -= flow;
        }
        totalFlow += flow;
    }
    cout << totalFlow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> c[0][i];
    }
    for(int i = N+1; i <= N+M; i++) {
        cin >> c[i][N+M+1];
    }
    for (int i = N+1; i <= N+M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> c[j][i];
        }
    }
    networkflow(0,N+M+1);
}