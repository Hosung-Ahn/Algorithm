#include<iostream>
using namespace std;
#define MAX 1001

int edges[MAX][MAX] = {0,};
int nxt[MAX];
int N;

void dfs(int cur) {
    for (int &next = nxt[cur]; next <= N; next++) {
        while(next <= N && edges[cur][next]) {
            edges[cur][next]--;
            edges[next][cur]--;
            dfs(next);
        }
    }
    cout << cur << " ";
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int cnt = 0; 
        for (int j = 1; j <= N; j++) {
            cnt += edges[i][j];
        }
        if (cnt % 2 != 0) {
            cout << -1;
            return;
        }
    }
    dfs(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> edges[i][j];
        }
    }
    for (int i = 0; i < MAX; i++) nxt[i] = 1;

    solve();
}