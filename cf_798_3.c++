#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 300100
vector<int> edges[MAX];
int cnt[MAX] = {0,};

int find_cnt(int c, int p) {
    int ret = 0;
    for (int next : edges[c]) {
        if (next == p) continue;
        ret += find_cnt(next, c) + 1; 
    }
    return cnt[c] = ret;
}

int find_ans(int c, int p) {
    if (c == 0) return 0;

    int l = 0, r = 0;
    bool ck = true;
    for (int next : edges[c]) {
        if (next == p) continue;
        if (ck) {
            l = next;
            ck = false;
        }
        else r = next;
    }

    return max(cnt[l] + find_ans(r, c), cnt[r] + find_ans(l,c));
}

void solve() {
    int N; cin >> N;

    memset(cnt, 0, sizeof(int)*MAX);

    for (int i = 0; i < N-1; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    find_cnt(1,-1);

    // for (int i = 1; i <= N; i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    cout << find_ans(1,-1) << "\n";

    for (int i = 0; i < MAX; i++) edges[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
