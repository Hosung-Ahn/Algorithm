# include <iostream>
# include <limits.h>
# include <string.h>
using namespace std;

# define MAX 101
# define ll long long

int N,M, A[MAX], B[MAX];
int dp[MAX][MAX];

void clear() {
    for (int i = 0; i < MAX; i++)
        memset(dp[i], -1, sizeof(int)*MAX);
}

int find_dp(int idxA, int idxB) {
    int &ret = dp[idxA][idxB];
    if (ret != -1) return ret;

    ll a = (idxA == 0 ? LLONG_MIN : A[idxA]);
    ll b = (idxB == 0 ? LLONG_MIN : B[idxB]);

    ll max_value = max(a,b);

    ret = 0;

    for (int nextA = idxA + 1; nextA <= N; nextA++) {
        if (A[nextA] > max_value) {
            ret = max(ret, find_dp(nextA, idxB) + 1);
        }
    }

    for (int nextB = idxB + 1; nextB <= M; nextB++) {
        if (B[nextB] > max_value) {
            ret = max(ret, find_dp(idxA, nextB) + 1);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        clear();
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= M; i++) {
            cin >> B[i];
        }

        cout << find_dp(0,0) << "\n";
    }
}