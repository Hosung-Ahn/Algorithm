#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        int A,B, AM = 0 ,BM = 0;
        cin >> A; 
        for (int i = 0; i < A; i++) {
            int x; cin >> x;
            if (x > AM) {
                AM = x;
            }
        }
        cin >> B;
        for (int i = 0; i < B; i++) {
            int x; cin >> x;
            if (x > BM) {
                BM = x;
            }
        }

        if (AM >= BM) cout << "Alice\n";
        else cout << "Bob\n";

        if (BM >= AM) cout << "Bob\n";
        else cout << "Alice\n";
    }

}