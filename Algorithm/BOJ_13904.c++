#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1001
int N;
vector<pair<int,int>> arr;
int dp[MAX][MAX] = {0,};

int find_dp(int idx, int cur_day) {
    int &ret = dp[idx][cur_day];
    if (ret != -1) return ret;
    if (cur_day >= arr[idx].first) return 0;
    ret = max(arr[idx].second + find_dp(idx+1, cur_day+1), find_dp(idx+1, cur_day));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for(int i=0;i<N;i++) {
        int d,v; cin >> d >> v;
        arr.push_back({d,v});
    }
    sort(arr.begin(), arr.end());
    cout << find_dp(0,0);
}
