#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
vector<string> board;
int R,C,MAX;
vector<vector<int>> dp(80, vector<int>(1024,-1));

string to_bin(int cur) {
    string ret = "";
    string tmp = "";
    while(cur) {
        if (cur%2==0) tmp.push_back('0');
        else tmp.push_back('1');
        cur/=2;
    }
    for(int i=0;i<C-tmp.size();i++) {
        ret.push_back('0');
    }
    for(int i=tmp.size()-1;i>=0;i--) {
        ret.push_back(tmp[i]);
    }
    return ret;
}

bool adjacent(int cur) {
    string bin = to_bin(cur);
    for(int i=0;i<C-1;i++) {
        if (bin[i] == '1' && bin[i+1] == '1') return true;
    }
    return false;
}

bool wall(int k, int cur) {
    string bin = to_bin(cur);
    for(int i=0;i<C;i++) {
        if (bin[i] == '1' && board[k][i] == 'x') return true;
    }
    return false;
}

bool up_adjacent(int cur, int up) {
    string cur_bin = to_bin(cur);
    string up_bin = to_bin(up);
    for(int i=0;i<C-1;i++) {
        if (up_bin[i] == '1' && cur_bin[i+1] == '1') return true;
        if (up_bin[i+1] == '1' && cur_bin[i] == '1') return true;
    }
    return false;
}

int cal_n(int cur) {
    int ret = 0;
    while(cur) {
        if(cur%2==1) ret++;
        cur/=2;
    }
    return ret;
}

int find_dp(int k, int cur) {
    int n = cal_n(cur);
    int ret = n;
    if (k==0) return ret;
    for(int up=0;up<MAX;up++) {
        if(adjacent(up) || wall(k-1,up) || up_adjacent(cur,up)) continue;
        if(dp[k-1][up] == -1) {
            dp[k-1][up] = find_dp(k-1,up);
        }
        ret = max(ret, n+dp[k-1][up]);
    }
    return ret;
}

void solve() {
    cin >> R >> C;
    for(int i=0;i<10;i++) {
        fill(dp[i].begin(), dp[i].end(), -1);
    }
    MAX = pow(2,C);
    board.clear();

    for(int i=0;i<R;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    int ans = 0;
    for(int cur=0;cur<MAX;cur++) {
        if (adjacent(cur) || wall(R-1, cur)) continue;
        ans = max(ans, find_dp(R-1,cur));
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}