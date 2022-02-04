# include <iostream>
# include <string.h>
# include <string>
# include <cstdio>

using namespace std;

# define MAX 2500
# define INF 10000

int dp[MAX][MAX] = {0,};
string str;

bool is_palin(int s, int e) {
    int mid = (e-s)/2;
    for (int i = 0; i <= mid; i++) {
        if (str[s+i] != str[e-i]) return false;
    }
    return true;
}

int find_dp(int s, int e) {
    if (dp[s][e] != 0) return dp[s][e]; 

    if (is_palin(s,e)) {
        dp[s][e] = 1;
        return dp[s][e];
    }   

    int result = INF;
    for (int mid = s; mid < e; mid++) {
        result = min(result, find_dp(s,mid) + find_dp(mid+1, e));
    }
    dp[s][e] = result;
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> str;
    int end = str.size()-1;

    cout << find_dp(0,end);

}



