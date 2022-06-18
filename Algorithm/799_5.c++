#include <iostream>
using namespace std;
#define MAX 200100
int arr[MAX];

void solve() {
    int N, S; cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int l = 0, ans = -1;
    for (int r = 0; r < N; r++) {
        S -= arr[r];
        while(S < 0) {
            S += arr[l++];
        }
        if (S==0) ans = max(ans, r-l+1);
    }
    cout << (ans == -1 ? -1 : N-ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
