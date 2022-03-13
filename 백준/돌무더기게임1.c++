# include <iostream>
using namespace std;

# define ll long long 

int main() {
    int T; cin >> T;
    while (T--) {
        int x,y,z; scanf("%d %d %d", &x,&y,&z);
        ll sum = x+y+z;
        if (sum % 2 == 0) {
            if ((sum/2) % 2 == 1) cout << "R\n";
            else cout << "B\n";
        }
        else {
            if ((sum/2) % 2 == 1) cout << "B\n";
            else cout << "R\n";
        }
    }
}