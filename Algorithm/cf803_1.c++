#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> arr;
    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int x = arr[i];
        int tmp = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            tmp ^= arr[j];
        }
        if (tmp == x) {
            cout << x << "\n";
            return;
        }
        cout << tmp << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}