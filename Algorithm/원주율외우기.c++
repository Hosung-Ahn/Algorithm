# include <iostream>
# include <string>
# include <string.h>
using namespace std;

# define MAX 10000
# define INF 987654321
int arr[MAX] = {0,};
int dp[MAX] = {0,};
int last = 0;

bool all_equal(int s, int e) {
    int start = arr[s];
    for (int i = s; i <= e; i++) {
        if (arr[i] != start) return false;
    }
    return true;
}

int ascending(int s, int e) {
    int diff = arr[s+1] - arr[s];
    for (int i = s+1; i <= e; i++) {
        if (arr[i] - arr[i-1] != diff) return 0;
    }
    if (diff == 1 || diff == -1) return 2;
    else return 5;
}

bool alternating(int s, int e) {
    int nums[2] = {0,};
    if (s % 2 == 0) {
        nums[0] = arr[s];
        nums[1] = arr[s+1];
    }
    else {
        nums[0] = arr[s+1];
        nums[1] = arr[s];
    }

    for (int i = s; i <= e; i++) {
        if (arr[i] != nums[i%2]) return false;
    }
    return true;
}

int cal(int s, int e) {
    if (all_equal(s,e)) return 1;
    int a = ascending(s,e);
    if (a != 0) return a;
    if (alternating(s,e)) return 4;
    return 10;
}

int find_dp(int n) {
    if (n == last) return 0;
    if (n > last) return INF;

    int &ret = dp[n];
    if (ret != 0) return ret;

    ret = INF;
    ret = min(ret, cal(n,n+2) + find_dp(n+3));
    ret = min(ret, cal(n,n+3) + find_dp(n+4));
    ret = min(ret, cal(n,n+4) + find_dp(n+5));
    return ret;
}

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        memset(dp, 0, sizeof(int)*MAX);
        last = s.size();
        for (int i = 0; i < s.size(); i++) {
            arr[i] = s[i]-'0';
        }
        cout << find_dp(0) << "\n";
    }
}