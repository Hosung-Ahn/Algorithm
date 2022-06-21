#include <iostream>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        ll n,m; cin >> n >> m;
        cout << m*(m-1)/2 + m*n*(n+1)/2 << "\n";
    }
}