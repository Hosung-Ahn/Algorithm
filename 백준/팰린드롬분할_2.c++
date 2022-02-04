# include <iostream>
# include <string.h>
# include <string>
# include <cstdio>

using namespace std;

# define MAX 2500
# define INF 10000

bool dp[MAX][MAX] = {0,};
int dp_cnt[MAX] = {0,};
string str;

void find_palin() {
    int end = str.size();
    for (int i = 0; i < end; i++) {
        dp[i][i] = true;
    }
    for (int i = 1; i < end; i++) {
        if (str[i-1] == str[i]) dp[i-1][i] = true;
    }
    for (int len = 3; len <= end; len++) {
        for (int i = 0; i <= end - len; i++) {
            if (str[i] == str[i+len-1] && dp[i+1][i+len-2]) dp[i][i+len-1] = true;
        }
    }
}

void find_min_cnt() {
    for (int end = 1; end <= str.size(); end++) {
        dp_cnt[end] = INF;
        for (int start = 1; start <= end; start++) {
            if (dp[start-1][end-1]) {
                dp_cnt[end] = min(dp_cnt[end], dp_cnt[start-1] + 1);
            }
        }
    }
}

int main() {
    cin >> str;
    find_palin();
    find_min_cnt();

    cout << dp_cnt[str.size()];
}

