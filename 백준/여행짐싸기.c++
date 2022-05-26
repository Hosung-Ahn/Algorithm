#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100
int N,W;
string names[MAX];
int w[MAX], v[MAX];
int dp[MAX][1001];
vector<string> ret;

int find_dp(int idx, int weight) {
    if (idx == N) return 0;
    if (weight - w[idx] < 0) return find_dp(idx+1, weight);
    int &ret = dp[idx][weight];
    if (ret != -1) return ret;

    ret = max(v[idx]+find_dp(idx+1, weight-w[idx]), find_dp(idx+1,weight));
    return ret;
}

void dfs(int idx, int weight) {
    if (idx == N) return;
    if (weight-w[idx] < 0) {
        dfs(idx+1, weight);
        return;
    }
    
    int a = v[idx] + find_dp(idx+1, weight-w[idx]);
    int b = find_dp(idx+1, weight);
    if (a > b) {
        ret.push_back(names[idx]);
        dfs(idx+1, weight-w[idx]);
    }
    else {
        dfs(idx+1, weight);
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> N >> W;
        for (int i = 0; i < N; i++) {
            string s;
            int a,b;
            cin >> s >> a >> b;
            names[i] = s;
            w[i] = a;
            v[i] = b;
        }

        for (int i = 0; i < MAX; i++) 
            memset(dp[i], -1, sizeof(int)*1001);

        cout << find_dp(0, W) << " ";
        dfs(0,W);
        cout << ret.size() << "\n";
        for (string s : ret) {
            cout << s << "\n";
        }
        ret.clear();
    }

}