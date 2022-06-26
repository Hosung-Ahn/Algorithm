#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 53
#define INF 987654321
int c[MAX][MAX] = {0,};
int f[MAX][MAX] = {0,};

void networkflow(int s, int e) {
    int totalFlow = 0;
    while(1) {
        vector<int> parent(MAX, -1);
        parent[s] = s;
        queue<int> q;
        q.push(s);

        while(!q.empty() && parent[e] == -1) {
            int cur = q.front(); q.pop();
            for (int next = 0; next < MAX; next++) {
                if (c[cur][next] - f[cur][next] > 0 && parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
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
            f[p][parent[p]] += -flow;
        }
        // cout << flow << endl;
        totalFlow += flow;
    }
    cout << totalFlow << "\n";
}

int to_idx(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c-'A' + 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int E; cin >> E;
    for (int i = 0; i < E; i++) {
        char s,e; int d; cin >> s >> e >> d;
        int si = to_idx(s), ei = to_idx(e);
        c[si][ei] += d;
        c[ei][si] += d;
    }

    networkflow(to_idx('A'), to_idx('Z'));
}