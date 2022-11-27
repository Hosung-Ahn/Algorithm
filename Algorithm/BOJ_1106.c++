#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int,int>> arr;
int dp[1001];

int find_dp(int C) {
    if (C <= 0) return 0;
    int &ret = dp[C];
    if (ret != -1) return ret;
    
    ret = 1000001;
    for(int i=0;i<arr.size();i++) {
        ret = min(ret, arr[i].first + find_dp(C - arr[i].second));
    }
    return ret;
}

int main() {
    int C,N; cin >> C >> N;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        arr.push_back({a,b});
    }
    memset(dp, -1, sizeof(dp));
    cout << find_dp(C) << endl;
}