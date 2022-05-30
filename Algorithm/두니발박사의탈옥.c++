#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 51
int N,D,P;
vector<vector<int>> edges(MAX, vector<int>());
double dp[101][MAX];

double find_dp(int d, int cur) {
    if (d == 0) {
        return cur == P ? 1 : 0;
    }
    double &ret = dp[d][cur];
    if (ret >= 0) return ret;

    ret = 0;

    for (int last : edges[cur]) { 
        ret += find_dp(d-1, last) * ((double)1/edges[last].size());
    } 
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        cin >> N >> D >> P;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < MAX; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < MAX; i++) {
            edges[i].clear();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int x; cin >> x;
                if (x == 1) {
                    edges[i].push_back(j);
                }
            }
        }
        // cout << find_dp(0,1);
        int K; cin >> K;
        for(int i = 0; i < K; i++) {
            int k; cin >> k;
            cout<<fixed;
            cout.precision(8);
            cout << find_dp(D,k) << " ";
        }
        cout << "\n";
    }
}