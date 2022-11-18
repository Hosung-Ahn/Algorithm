#include <iostream>
using namespace std;
#define MAX 1000
int pre[MAX], in[MAX];
int idx = 0;

int find_mid(int x, int s, int e) {
    for(int i=s;i<=e;i++) {
        if (x == in[i]) return i;
    }
    return -1;
}

void post(int s, int e) {
    if (s > e) return;
    int x = pre[idx++];
    int mid = find_mid(x, s, e);
    post(s, mid-1);
    post(mid+1, e);
    cout << x << " ";
}

void solve() {
    int N; cin >> N;
    for(int i=0;i<N;i++) cin >> pre[i];
    for(int i=0;i<N;i++) cin >> in[i];
    idx = 0;
    post(0,N-1);
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}