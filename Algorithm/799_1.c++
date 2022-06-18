#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int a; cin >> a;
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            int x; cin >> x;
            if (x > a) cnt++;
        }
        cout << cnt << "\n";
    }
}