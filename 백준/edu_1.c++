# include <iostream>
# include <math.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int x,y; scanf("%d %d", &x,&y);
        int tmp = pow(x*x + y*y, 0.5);
        if (x == 0 && y == 0) cout << "0\n";
        else if (tmp*tmp == (x*x + y*y)) cout << "1\n";
        else cout << "2\n";
    }
}

