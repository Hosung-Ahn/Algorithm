# include <iostream>
# include <vector>
# define MAX_BEG 101
# define MAX_K 1000001

using namespace std;

int N,K; 
int dp[MAX_K][MAX_BEG] = {0, };
vector<pair<int,int>> beg;

void solve() {
    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n++){
            int wc = beg[n-1].first;
            int vc = beg[n-1].second;

            if (k >= wc) {
                dp[k][n] = max(dp[k][n-1], vc + dp[k-wc][n-1]); 
            }
            else dp[k][n] = dp[k][n-1];
        }
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int W,V; cin >> W >> V;
        beg.push_back(make_pair(W,V));
    }

    solve();

    cout << dp[K][N] << endl;

}