#include <iostream>
using namespace std;
#define MAX 20
#define INF 987654321

int dist[MAX][MAX];
int ans = 0;
int N;

bool floyd() {
    bool ret = false;
    for(int s=0;s<N;s++) {
        for(int e=0;e<N;e++) {
            if (s == e) continue;
            for(int m=0;m<N;m++) {
                if(s==m || e==m) continue;
                if(dist[s][e] > dist[s][m]+dist[m][e]) {
                    dist[s][e] = dist[s][m]+dist[m][e];
                    ret = true;
                }
            }
        }
    }
    return ret;
}

void solve() {
    if (floyd()) {
        cout << -1;
        return;
    }

    for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(i<j){
        int x = dist[i][j];
        dist[i][j] = INF;
        floyd();
        if(dist[i][j] == x) ans -= x;
        else dist[i][j] = x;
    }
    cout << ans;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        cin >> dist[i][j];
        if (i<j) ans += dist[i][j];
    }
    solve();
}