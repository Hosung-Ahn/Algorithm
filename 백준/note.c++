# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    int x = 1 << 1;
    int y = 1 << 0;

    cout << x << endl;
    cout << y << endl;

    int z = x | y;
    cout << z << endl;
}