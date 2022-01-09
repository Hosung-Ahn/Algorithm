# include <iostream>
# include <set>
# include <bitset>
using namespace std;

int main() {
    bitset<101> bit;

    cout << bit[102] << endl;

    int x = -20;

    x %= 6;

    cout << x << endl;
}