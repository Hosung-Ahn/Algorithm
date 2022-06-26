#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 310
#define INF 987654321
int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};

void networkflow(int s, int e) {
    int totalFlow = 0;
    while(1) {
        vector<int> parent(MAX, -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;

        while(!q.empty() && parent[e] == -1) {
            int cur = q.front(); q.pop();
            for (int next = 0; next < MAX; next ++) {
                if (c[cur][next] - f[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                }
            }
        }

        if (parent[e] == -1) break;

        int flow = INF;
        for (int p = e; p != s; p = parent[p]) {
            flow = min(flow, c[parent[p]][p] - f[parent[p]][p]);
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
    int N,K,D; cin >> N >> K >> D;
    for (int p = 1; p <= N; p++) {
        c[0][p] = K;
    }
    for (int i = 1; i <= D; i++) {
        int d; cin >> d;
        c[N+i][N+D+1] = d;
    }
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int d; cin >> d;
            c[i][d+N] = 1;
        }
    }

    networkflow(0,N+D+1);
}