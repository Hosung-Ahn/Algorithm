#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10
int connect[MAX][MAX] = {0,};
int N;
int ans = 0;

void brute(vector<bool> &matched) {
    int cur = -1;
    for (int tmp = 0; tmp < N; tmp++) {
        if(!matched[tmp]) {
            cur = tmp;
            break;
        }
    }
    if (cur == -1) {
        ans++;
        return;
    }

    for(int other = 0; other < N; other++) {
        if (matched[other] || !connect[cur][other]) continue;
        matched[cur] = true;
        matched[other] = true;
        brute(matched);
        matched[cur] = false;
        matched[other] = false;
    }
}

void solve() {
    int E; cin >> N >> E;
    ans = 0;
    memset(connect, 0, sizeof(connect));
    for(int i=0; i<E; i++) {
        int a,b; cin >> a >> b;
        connect[a][b] = true;
        connect[b][a] = true;
    }
    vector<bool> matched(N, false);
    brute(matched);
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}