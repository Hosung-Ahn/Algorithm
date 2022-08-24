#include<iostream>
using namespace std;
#define MAX 10000
#define ll long long
#define INF 9223372036854775807
#define PMAX 2000000000

int arr[MAX];
int N,M;

// t초가 지났을 때 탄 사람 수
ll f(ll t) {
    ll ret = 0;
    for(int i=0;i<M;i++) {
        ret += (t/arr[i])+1;
        if (ret > PMAX) return PMAX+1000;
    }
    return ret;
}

ll lower(int N) {
    ll lo = 0, hi = INF;
    while(lo < hi) {
        ll mid = (lo+hi)/2;
        ll tmp = f(mid);

        if (tmp < N) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

void solve() {
    ll k = lower(N);
    ll TN = f(k);

    // cout << k << " " << TN << endl;

    // t=0이거나 t=k 일 때 TN=N 이 된 경우
    if (TN >= N) {
        for(int i=M-1;i>=0;i--) {
            if (k % arr[i] == 0) {
                if (TN == N) {
                    cout << i+1;
                    return;
                }
                TN--;
            }
        }
    }
    
    // t=k+1 일 때 TN>=N 이 되는 경우
    else { 
        for(int i=0;i<M;i++) {
            if ( (k+1) % arr[i] == 0) {
                TN++;
                if (TN == N) {
                    cout << i+1;
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> arr[i];
    solve();
}