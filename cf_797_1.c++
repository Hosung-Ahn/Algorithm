#include<iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    int op = n % 3;
    switch (op) {
        case 0 : {
            cout << n/3 << " " << n/3+1 << " " << n/3-1 << "\n";
            break;
        }   
        case 1 : {
            cout << n/3 << " " << n/3+2 << " " << n/3-1 << "\n";
            break;
        }
        case 2 : {
            cout << n/3+1 << " " << n/3+2 << " " << n/3-1 << "\n";
            break;
        }
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
