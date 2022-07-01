#include<iostream>
#include<vector>
using namespace std;
#define MAX 200010
#define ll long long
vector<int> Left, Right;
vector<int> edges[MAX];
int ans = 0;

ll dfs(int cur, int parent) {
    int cnt = 0;
    ll sum = 0;
    for (int next : edges[cur]) {
        if (next == parent) continue;
        sum += dfs(next, cur);
        cnt++;
    }
    if (cnt == 0 || sum < Left[cur]) {
        ans++;
        return Right[cur];
    }
    return min(sum, (ll)Right[cur]);
}

void clear(int N) {
    Left.clear();
    Right.clear();
    Left.resize(N+1);
    Right.resize(N+1);
    for (int i = 0; i <= N; i++) {
        edges[i].clear();
    }
}

void solve() {
    int N; cin >> N;
    clear(N);
    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        edges[i].push_back(p);
        edges[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> Left[i] >> Right[i];
    }
    ans = 0;
    dfs(1,-1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
