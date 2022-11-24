#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
# define MAX 10000001
# define ll long long
bool prime[MAX];
vector<ll> prime_square_arr;

void find_prime() {
    memset(prime, 1, sizeof(prime));
    int check = sqrt(MAX);
    for(int i=2;i<=check;i++) {
        if (prime[i]) {
            for(int j=i*2;j<MAX;j+=i) prime[j] = false;
        }
    }

    for(ll i=1;i<MAX;i++) if(prime[i]) prime_square_arr.push_back(i*i);
}

int main() {
    find_prime();
    ll a,b; cin >> a >> b;
    vector<ll>::iterator lo, hi;
    lo = lower_bound(prime_square_arr.begin(), prime_square_arr.end(), a);
    hi = lower_bound(prime_square_arr.begin(), prime_square_arr.end(), b);

    cout << *lo << " " << *hi << endl;

    if (*lo == a && *hi == b) cout << hi-lo+1;
    else cout << hi-lo;
}

