# include <iostream>
# include <math.h>
using namespace std;
# define ll long long

ll N,K;

ll under_num(ll num) {
    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        ret += min(N, num/i);
    }
    return ret;
}

void bi_search() {
    ll lo = 1;
    ll hi = N*N;

    while(lo != hi) {
        ll mid = (lo+hi)/2;
        if (under_num(mid) < K) lo = mid+1;
        else hi = mid;
    }

    cout << lo;
}

int main() {
    cin >> N >> K;

    bi_search();
    
}