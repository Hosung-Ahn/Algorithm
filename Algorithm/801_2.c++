#include <iostream>
using namespace std;
#define MAX 51


void solve() {
    int N; cin >> N;
    int arr[MAX];
    int ma = 1000000000, mi;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (ma > arr[i]) {
            mi = i;
            ma = arr[i];
        }
    }


    if (N % 2 == 1) cout << "Mike\n";
    else {
        if (mi % 2 == 0) cout << "Mike\n";
        else cout << "Joe\n";
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