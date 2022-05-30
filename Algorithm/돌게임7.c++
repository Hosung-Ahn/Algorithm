# include <iostream>
using namespace std;

# define ll long long

int main() {
    ll N; cin >> N;
    int x = N % 5;
    if (x == 0 || x == 2) cout << "CY";
    else cout << "SK";
}