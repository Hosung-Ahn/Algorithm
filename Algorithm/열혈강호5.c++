#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 810
#define INF 987654321
#define S 0
#define E 805

int N,M;
vector<int> edges[MAX];
int cp[MAX][MAX] = {0,};
int fl[MAX][MAX] = {0,};
int d[MAX][MAX] = {0,};

bool inQ[MAX] = {0,};

void mcmf() {
    int totalFlow = 0;
    int totalCost = 0;

    while(1) {
        vector<int> parent(MAX, -1);
        vector<int> dist(MAX, INF);
        memset(inQ, 0, sizeof(bool)*MAX);
        dist[S] = 0;
        parent[S] = S;
        inQ[S] = true;
        queue<int> q;
        q.push(S);

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            inQ[cur] = false;

            for (int next : edges[cur]) {
                if (cp[cur][next] - fl[cur][next] && dist[next] > dist[cur] + d[cur][next]) {
                    dist[next] = dist[cur] + d[cur][next];
                    parent[next] = cur;

                    if (inQ[next]) continue;
                    q.push(next);
                    inQ[next] = true;
                }
            }
        }

        if (parent[E] == -1) break;

        int flow = INF;
        for (int p = E; p != S; p = parent[p]) {
            flow = min(flow, cp[parent[p]][p] - fl[parent[p]][p]);
        }

        for (int p = E; p != S; p = parent[p]) {
            totalCost += flow*d[parent[p]][p];
            fl[parent[p]][p] += flow;
            fl[p][parent[p]] -= flow;
        }
        totalFlow += flow;
    }

    cout << totalFlow << "\n" << totalCost;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cp[S][i] = 1;
        edges[S].push_back(i);
        edges[i].push_back(S);
    }
    for (int i = 1; i <= M; i++) {
        cp[i+N][E] = 1;
        edges[i+N].push_back(E);
        edges[E].push_back(i+N);
    }
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int b,c; cin >> b >> c;
            cp[i][b+N] = 1;

            edges[i].push_back(b+N);
            edges[b+N].push_back(i);

            d[i][b+N] = c;
            d[b+N][i] = -c;
        }
    }

    mcmf();
}