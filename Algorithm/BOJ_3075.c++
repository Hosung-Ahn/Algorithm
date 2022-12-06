#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define INF 987654321
#define MAX 101
int dist[MAX][MAX];

void solve() {
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) {
        if (i==j) dist[i][j] = 0;
        else dist[i][j] = INF;
    }
    int N,V,E; cin >> N >> V >> E;
    vector<int> nodes;
    nodes.resize(N);
    for(int i=0;i<N;i++) cin >> nodes[i]; 

    for(int i=0;i<E;i++) {
        int s,e,d; cin >> s >> e >> d;
        dist[s][e] = min(dist[s][e], d);
        dist[e][s] = min(dist[e][s], d);
    }

    for(int m=1;m<=V;m++) {
        for(int s=1;s<=V;s++) {
            if (m == s) continue;
            for(int e=1;e<=V;e++) {
                if (e == m || e == s) continue;
                dist[s][e] = min(dist[s][e], dist[s][m] + dist[m][e]);
            }
        }
    }

    ll min_val = 98765432100;
    int res_meet = 0;
    for(int meet=1;meet<=V;meet++) {
        ll tmp = 0;

        bool ck = false;
        for(int node : nodes) {
            if (dist[node][meet] == INF) {
                ck = true;
                break;
            }
            tmp += (ll)dist[node][meet] * dist[node][meet];
        }
        if (ck) break;
        
        if (tmp < min_val) {
            res_meet = meet;    
            min_val = tmp;
        }
    }
    cout << res_meet << " " << min_val << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}