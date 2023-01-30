#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 5000001
bool prime[MAX];
vector<int> prime_arr;
int factor[MAX] = {0,};

void find_prime() {
    int check = pow(MAX,0.5);
    memset(prime, 1, sizeof(prime));
    for(int i=2;i<=check;i++) if(prime[i]){
        for(int j=2*i;j<MAX;j+=i) prime[j] = false;
    }
    for(int i=2;i<MAX;i++) if(prime[i]) prime_arr.push_back(i);
}

void find_factor() {
    for(auto p : prime_arr) {
        for(int np=p;np<MAX;np+=p) if (factor[np]==0) {
            factor[np] = p;
        }
    }
}

void print_factor(int x) {
    while(factor[x] != x) {
        cout << factor[x] << " ";
        x /= factor[x];
    }
    cout << x << "\n";
}

void solve() {
    find_prime(); 
    find_factor();

    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        print_factor(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    solve();
}