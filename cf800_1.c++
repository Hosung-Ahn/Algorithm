#include<iostream>
using namespace std;

void solve() {
    int a,b; cin >> a >> b;
    if (a > b) {
        for (int i = 0; i < a-b; i++) cout << "0";
        for (int i = 0; i < b; i++) cout << "10";
    }
    else {
        for (int i = 0; i < b-a; i++) cout << "1";
        for (int i = 0; i < a; i++) cout << "01";
    }
    cout << "\n";
}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}