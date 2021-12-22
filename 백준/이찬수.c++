# include <iostream>
# include <vector>

using namespace std;

# define ll long long

int n;
ll fivo[90];

int main() {
    fivo[0] = 0;
    fivo[1] = 1;

    cin >> n;

    for (int i = 2; i <= n; i++) {
        fivo[i] = fivo[i-1] + fivo[i-2];
    }

    cout << fivo[n] << endl;
}
