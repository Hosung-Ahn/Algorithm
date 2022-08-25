#include<iostream>
using namespace std;
#define TMAX 90000000000
#define NMAX 3000000000
#define ll long long
int arr[10000];
int N,M;

ll f(ll t) {
    ll ret = 0;
    for(int i=0;i<M;i++){
        ret += (t/arr[i]) + 1;
        if (ret > NMAX) return NMAX;
    }
    return ret;
}

ll lower() {
    ll lo = 0, hi = TMAX;
    while(lo < hi) {
        ll mid = (lo+hi)/2;
        ll TN = f(mid);
        if (TN < N) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

void solve() {
    ll t = lower();
    ll TN = f(t);
    for(int i=M-1;i>=0;i--) if(t%arr[i] == 0) {
        if (TN==N) {
            cout << i+1;
            return;
        }
        TN--;
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) cin>>arr[i];
    solve();
}