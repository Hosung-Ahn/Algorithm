#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 
int N,S;
vector<pair<int,int>> arr;
int dp[300001];

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int under_bound(int x) {
    int lo = 0, hi = arr.size()-1;
    while(lo < hi) {
        int mid = (lo+hi)/2;
        if (arr[mid].first < x) lo = mid+1;
        else hi = mid;
    }
    return lo;
}

int find_dp(int idx) {
    int &ret = dp[idx];
    if (ret != -1) return ret;

    int fick_idx = under_bound(arr[idx].first + S);
    int not_fick_idx = under_bound(arr[idx].first + 1);

    int fick_dp;
    if (arr[idx].first + S > arr[fick_idx].first) 
        fick_dp = arr[idx].second;
    else fick_dp = arr[idx].second + find_dp(fick_idx);

    int not_fick_dp;
    if (idx == not_fick_idx) not_fick_dp = 0;
    else not_fick_dp = find_dp(not_fick_idx);
    ret = max(fick_dp, not_fick_dp);
    return ret;
}

void solve() {
    sort(arr.begin(), arr.end(), cmp);
    memset(dp, -1, sizeof(dp));
    // cout << endl;
    // for(auto pair : arr) {
    //     cout << pair.first << " " << pair.second << endl;
    // }
    int start = under_bound(S);
    if (arr[start].first < S) {
        cout << 0;
        return;
    }
    // cout << start << endl;
    cout << find_dp(start);
    // cout << endl;

    // for(int i=0;i<N;i++) {
    //     cout << dp[i] << " "; 
    // }
}

int main() {
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        arr.push_back({a,b});
    }
    solve();
}