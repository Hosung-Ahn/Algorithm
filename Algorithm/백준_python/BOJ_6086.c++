#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321
#define MAX 53
#define S 27
#define E 52

int cap[MAX][MAX] = {0,};
int flow[MAX][MAX] = {0,};
int M;
vector<int> parent(MAX, -1);
vector<int> edges[MAX];

int to_int(char a) {
    if (a >= 'A' && a <= 'Z') return a-'A'+27;
    return a-'a'+1;
}

void network_flow() {
    int result = 0;
    while(1) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(S);

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int next : edges[cur]) {
                if (cap[cur][next]-flow[cur][next]>0 && parent[next]==-1) {
                    parent[next] = cur;
                    q.push(next);
                    if (next == E) break;
                }
            }
        }
        if (parent[E] == -1) break;

        int min_flow = INF;
        for(int i=E;i!=S;i=parent[i]) {
            min_flow = min(min_flow, cap[parent[i]][i]-flow[parent[i]][i] );
        }

        for(int i=E;i!=S;i=parent[i]) {
            flow[parent[i]][i] += min_flow;
            flow[i][parent[i]] -= min_flow;
        }
        result += min_flow;
    }

    cout << result;
}

int main() {
    cin >> M;
    for(int i=0;i<M;i++) {
        char a,b; int c;
        cin >> a >> b >> c;
        int s = to_int(a);
        int e = to_int(b);
        // cout << s << " " << e << endl;
        edges[s].push_back(e);
        edges[e].push_back(s);
        cap[s][e] += c;
        cap[e][s] += c;
    }

    network_flow();
}