# include <iostream>
# include <math.h>
using namespace std;

bool is_coprime(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    if (b != 1) return false;
    return true;
}

int main() {
    int gcd, lcm; cin >> gcd >> lcm;
    int n = lcm / gcd;
    int check = pow(n,0.5);
    
    if (gcd == lcm) cout << gcd << " " << gcd << endl;
    else { 
        int a,b;
        for (int i = 1; i <= check; i++) {
            if (n % i == 0 && is_coprime(i,n/i)) {
                a = i;
                b = n/i;
            }
        }

        cout << a*gcd << " " << b*gcd << endl;
    }
}