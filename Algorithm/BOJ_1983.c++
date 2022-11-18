#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 401
#define INF -987654321
int N;
vector<int> up,down;
int dp[MAX][MAX][MAX];

int find_dp(int up_idx, int down_idx, int len) {
    if (up_idx == up.size() && down_idx == down.size()) return 0;
    int &ret = dp[up_idx][down_idx][len];
    if (ret != INF) return ret;

    if (up.size() - up_idx < len && down.size() - down_idx < len) {
        ret = max(ret, find_dp(up_idx, down_idx, len-1));
    }
    if (up.size() - up_idx < len && down_idx < down.size()) {
        ret = max(ret, find_dp(up_idx, down_idx+1, len-1));
    }
    if (down.size() - down_idx < len && up_idx < up.size()) {
        ret = max(ret, find_dp(up_idx+1, down_idx, len-1));
    }
    if (down_idx < down.size() && up_idx < up.size()) {
        ret = max(ret, up[up_idx]*down[down_idx] + find_dp(up_idx+1, down_idx+1, len-1));
    }

    cout << up_idx << " " << down_idx << " " << len << " " << ret << endl;
    return ret;
}

void solve() {
    if (up.empty() || down.empty()) {
        cout << 0;
        return;
    }
    for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) for(int k=0;k<MAX;k++) {
        dp[i][j][k] = INF;
    }
    cout << find_dp(0,0,N);
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        if (x != 0) up.push_back(x);
    }
    for(int i=0;i<N;i++){
        int x; cin >> x;
        if(x != 0) down.push_back(x);
    }
    solve();
    
} 