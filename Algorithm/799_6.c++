#include <iostream>
#include <vector>
#include <map>
using namespace std;
int cnt[10];

void solve() {
    int N; cin >> N;

    for (int i = 0; i < 10; i++) cnt[i] = 0;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        cnt[x%10]++;
    }

    for(int i = 0; i < 10; i++) if(cnt[i]>0) {
        cnt[i]--;
        for (int j = i; j < 10; j++) if(cnt[j]>0) {
            cnt[j]--;
            int k = (3-i-j+20)%10;
            if (cnt[k] > 0) {
                cout << "YES\n";
                return;
            }
            cnt[j]++;
        }
        cnt[i]++;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;

    while(T--) {
        solve();
    }

}