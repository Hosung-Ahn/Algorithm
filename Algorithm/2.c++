# include <iostream>
using namespace std;
# define ll long long

ll N,K;

int bi_sr(ll n, ll num) {
    int lo = 0;
    int hi = N;

    while (lo != hi) {
        // cout << lo << " " << hi  << " " << n << " " << num << endl;
        int mid = (lo+hi)/2+1;
        if (num >= n*mid) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

ll kth_num(ll num) {
    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        ret += bi_sr(i,num);
    }

    return ret;
}

void bi_sr_sol() {
    ll lo = 1;
    ll hi = N*N;

    while (lo != hi) {
        ll mid = kth_num((lo+hi)/2);
        // cout << lo << " " << hi << endl;
        if (mid < K) lo = mid+1;
        else hi = mid;
    }
    cout << lo;
}

int main(){
    for (int n = 1; n <= 10; n++) {
        for (int k = 1; k <= n*n; k++) {
            N = n;
            K = k;
            cout << N << " " << K << " : ";
            bi_sr_sol();
            cout << endl;
        }
    }
    // N = 1;
    // K = 2;
    // bi_sr_sol(); 
    
}