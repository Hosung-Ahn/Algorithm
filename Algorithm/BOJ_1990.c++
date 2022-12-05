#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> primes;

bool is_prime(int n) {
    if (n<=1) return false;
    int check = pow(n, 0.5);
    for(int d=2;d<=check;d++) {
        if (n % d == 0) return false;
    }
    return true;
}

void dfs(string s) {
    if(s.size() >= 9) return;
    int n = stoi(s);
    if (is_prime(n)) primes.push_back(n);
    for(int i=0;i<10;i++) {
        string nxt_s = s;
        nxt_s.insert(nxt_s.begin(), '0'+i);
        nxt_s.push_back('0'+i);
        dfs(nxt_s);
    }
}

void solve() {
    for(int i=0;i<10;i++) {
        string s = "";
        s.push_back('0'+i);
        dfs(s);
        s.push_back('0'+i);
        dfs(s);
    }

    sort(primes.begin(), primes.end());
    int a,b; cin >> a >> b;
    vector<int>::iterator s = lower_bound(primes.begin(), primes.end(), a), 
                          e = upper_bound(primes.begin(), primes.end(), b);
    for(;s!=e;s++) {
        cout << *s << "\n";
    }
    cout << -1;
}

int main() { 
    solve();
}