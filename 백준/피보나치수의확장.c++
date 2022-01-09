# include <iostream>
# include <string.h>
using namespace std;

# define MAX 1000000
# define MOD 1000000000

int fivo[MAX+1];

int main() {
    fivo[0] = 0;
    fivo[1] = 1;

    for (int i =2; i <= MAX; i++) {
        fivo[i] = (fivo[i-1] + fivo[i-2]) % MOD;
    }

    int n; cin >> n;

    if (n == 0) cout << "0\n0\n";
    else if (n > 0) printf("1\n%d\n", fivo[n]);
    else {
        if (n%2 == 0) printf("-1\n%d\n", fivo[-n]);
        else printf("1\n%d\n", fivo[-n]);
    }
} 