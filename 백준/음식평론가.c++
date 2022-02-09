# include <iostream>
using namespace std;

int func(int a, int b) {
    if (a % b == 0) return 0;
    if (a > b) return func(a%b, b);

    if (b % a == 0) return b - a;
    return (b/a) * a + func(a, b%a);
}

int main() {
    int a,b; cin >> a >> b;
    cout << func(a,b);
}