#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
#define MAX 100
#define ll long long

int n,m; 
int A[MAX], B[MAX];
int dp[MAX+1][MAX+1];
ll NEGINF = INT64_MIN;

int find_dp(int idxA, int idxB) {
    int &ret = dp[idxA+1][idxB+1];
    if (ret != -1) return ret;

    ll a = (idxA == -1 ? NEGINF : A[idxA]);
    ll b = (idxB == -1 ? NEGINF : B[idxB]);

    ll maxElement = max(a,b);

    ret = 0;

    for(int nextA = idxA+1; nextA < n; nextA++) {
        if (maxElement < A[nextA]) {
            ret = max(ret, find_dp(nextA, idxB)+1);
        }
    }
    for(int nextB = idxB+1; nextB < m; nextB++) {
        if (maxElement < B[nextB]) {
            ret = max(ret, find_dp(idxA, nextB)+1);
        }
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];
    cout << find_dp(-1,-1) << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}