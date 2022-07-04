#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 1001

int N; 
vector<int> arr(MAX,0), ans(MAX,0);
vector<bool> used(MAX,0);

bool dfs(int i) {
    if (i == N) return true;

    for (int next = 1; next <= N; next++) {
        if (used[next] || next == arr[i]) continue;
        used[next] = true;
        ans[i] = next;
        if (dfs(i+1)) return true;
        used[next] = false;
    }
    return false;
}

void solve() {
    fill(used.begin(), used.end(), false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    if (dfs(0)) {
        for (int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
