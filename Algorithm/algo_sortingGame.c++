#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
map<vector<int>, int> toSort;

void precal(int n) {
    vector<int> perm(n);
    for(int i=0;i<n;i++) perm[i]=i;
    queue<vector<int>> q;
    q.push(perm);
    toSort[perm] = 0;

    while(!q.empty()) {
        vector<int> cur = q.front();
        q.pop();

        int cost = toSort[cur];
        for(int i=0;i<n;i++) {
            for(int j=i+2;j<=n;j++) {
                reverse(cur.begin()+i, cur.begin()+j);
                if (toSort.count(cur) == 0) {
                    toSort[cur] = cost+1;
                    q.push(cur);
                }
                reverse(cur.begin()+i, cur.begin()+j);
            }
        }
    }
}

void solve() {
    int N; cin >> N;
    vector<int> perm(N);
    for(int i=0;i<N;i++) cin >> perm[i];
    vector<int> fixed;
    for(int a : perm) {
        int smaller = 0;
        for(int i=0;i<N;i++) if (perm[i] < a) smaller++;
        fixed.push_back(smaller);
    }
    cout << toSort[fixed] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    for(int n=1;n<=8;n++) precal(n);

    while(T--) {
        solve();
    }
}