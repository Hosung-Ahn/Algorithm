#include <iostream>
using namespace std;
#define MAX 200100

int cal()

void solve() {
    int N, K; cin >> N >> K;
    int arr[MAX];
    bool is_up[MAX] = {0,};
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 1; i < N; i++) if (2*arr[i] > arr[i-1]) {
        is_up[i] = true;
    }
    int cnt = 0, result = 0;
    for(int i = 0; i < N; i++) {
        if (is_up[i]) {
            cnt++;
            if (cnt >= K) result++;
        }
        else cnt = 0;
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}