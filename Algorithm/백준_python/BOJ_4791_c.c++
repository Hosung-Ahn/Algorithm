#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10001];
vector<pair<int,int>> arr;

int find_dp(int money) {
    int &ret = dp[money];
    if (ret != -1) return ret;

    ret = 0;
    for (int i=0;i<arr.size();i++) {
        int c = arr[i].second;
        int m = arr[i].first;
        if (money < m) break;
        ret = max(ret, c+find_dp(money-m));
    }
    return ret;
}

bool solve() {
    int N; float ftotal; cin >> N >> ftotal;
    int total = ftotal*100 + 0.5;

    if (N==0 && total==0) return false;

    arr.clear();
    memset(dp, -1, sizeof(int)*10001);

    for (int i=0;i<N;i++) {
        int c; float fm; cin >> c >> fm;
        int m = fm*100+0.5;
        arr.push_back({m,c});
    }
    sort(arr.begin(), arr.end());
    cout << find_dp(total) << "\n";
    return true;
}

int main() {
    while (solve()) {}
}