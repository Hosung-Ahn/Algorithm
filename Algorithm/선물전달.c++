# include <iostream>
using namespace std;

# define MOD 1000000000
# define ll long long 

void func(int n) {
    if (n == 1) {
        cout << 0;
        return;
    }
    if (n == 2) {
        cout << 1;
        return;
    }

    ll x = -1;
    if (n % 2 == 0) x = 1;

    ll result = x;
    while (n != 2) {
        x *= -n--;
        x %= MOD;
        result += x;
        result %= MOD;
    }
    if (result < 0) result += MOD;
    cout << result;
}

int main() {
    int N; cin >> N;
    func(N);
}