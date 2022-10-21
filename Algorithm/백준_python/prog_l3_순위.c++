#include <string>
#include <vector>

using namespace std;
#define MAX 101
#define INF 987654321
int dist[MAX][MAX];
vector<int> edges[MAX];

void floyd(int n) {
    for (int m=1;m<=n;m++) {
        for (int s=1;s<=n;s++) {
            if (m==s) continue;
            for(int e=1;e<=n;e++) {
                if (e==m || e==s) continue;
                dist[s][e] = min(dist[s][e], dist[s][m]+dist[m][e]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=INF;

    for(int i=0;i<results.size();i++) {
        int a = results[i][0];
        int b = results[i][1];
        edges[b].push_back(a);
        dist[b][a] = 1;
    }

    floyd(n);

    int ans = 0;

    for(int i=1;i<=n;i++) {
        int cnt = 0;
        for(int j=1;j<=n;j++) {
            if(dist[i][j]!=INF || dist[j][i]!=INF) cnt++;
        }
        if (cnt==n-1) ans++;
    }
    return ans; 
}