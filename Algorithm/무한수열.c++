# include <iostream>
# include <map>
using namespace std;

# define ll long long

map<ll,ll> dp;
ll N;
int P,Q;

ll find_dp(ll N) {
    if (N == 0) return 1;
    if (dp[N] != 0) return dp[N];

    ll result = find_dp(N/P) + find_dp(N/Q);
    dp[N] = result;
    return result;

}

int main() {
    cin >> N >> P >> Q;
    cout << find_dp(N);
}