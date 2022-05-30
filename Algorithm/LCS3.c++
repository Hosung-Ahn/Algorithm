# include <iostream>
# include <string>
# include <string.h>
using namespace std;

# define MAX 100

int dp[MAX][MAX][MAX];
string s1,s2,s3;

int find_dp(int i1, int i2, int i3) {
    
    if (i1 < 0 || i2 < 0 || i3 < 0) return 0;
    if (dp[i1][i2][i3] != -1) return dp[i1][i2][i3];

    int result = 0;
    if (s1[i1] == s2[i2] && s2[i2] == s3[i3]) {
        result = 1 + find_dp(i1-1, i2-1, i3-1);
    }
    else {
        result = max(max(find_dp(i1-1,i2,i3), find_dp(i1,i2-1,i3)), find_dp(i1,i2,i3-1));
    }
    dp[i1][i2][i3] = result;
    return result;
}

int main() {
    cin >> s1 >> s2 >> s3;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++) {
            memset(dp[i][j], -1, sizeof(int)*MAX);
        }
    }

    cout << find_dp(s1.size()-1, s2.size()-1, s3.size()-1);




}