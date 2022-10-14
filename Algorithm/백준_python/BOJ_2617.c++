#include <iostream>
using namespace std;
#define MAX 100
#define INF 987654321 

int dist[MAX][MAX];
int N,M;

void floyd() {
    for(int m=1;m<=N;m++) {
        for(int s=1;s<=N;s++) {
            if(s==m) continue;
            for(int e=1;e<=N;e++) {
                if(e==m || e==s) continue;
                dist[s][e] = min(dist[s][e], dist[s][m]+dist[m][e]);
            }
        }
    }
}

void solve() {
    floyd();
    int ans = 0;
    for(int n=1;n<=N;n++) {
        int over = 0, under = 0;
        for(int i=1;i<=N;i++) {
            if (i==n) continue;
            if (dist[n][i] != INF) over++;
            if (dist[i][n] != INF) under++;
        }
        if (over > N/2 || under > N/2) ans++;
    }
    cout << ans;
}

int main() {
    fill(&dist[0][0], &dist[MAX-1][MAX], INF);
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int s, e; cin >> s >> e;
        dist[e][s] = 1;
    }
    solve();
}