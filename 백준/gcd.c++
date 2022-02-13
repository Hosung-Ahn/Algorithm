# include <iostream>
# include <math.h>
# include <vector>
# include <set>
using namespace std;

# define ll long long

vector<int> primes;
set<ll> divisors;

bool find_divisors(ll &num) {
    int check = pow(num, 0.5);
    for (int d : primes) {
        if (d > check) break;

        if (num % d == 0) {
            divisors.insert(d);
            num /= d;
            return true;
        }
    }
    return false;
}

void factorization(ll &num) {
    ll result = num;
    while (find_divisors(num)) { }
    
    if (num != 1) {
        divisors.insert(num);
    }

    for (ll d : divisors) {
        result /= d;
        result *= d-1;
    }
    cout << result;
}


int main() {
    vector<bool> arr(1000001,true);
    for (int i = 2; i <= 1000; i++) {
        if (arr[i]) {
            for (int k = 2*i; k <= 1000000; k += i) {
                arr[k] = false;
            }
        }
    }
    
    for (int i = 2; i <= 1000000; i++) {
        if (arr[i]) primes.push_back(i);
    }

    ll N; cin >> N;
    factorization(N);
    
}