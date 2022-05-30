# include <iostream>
# include <string>
# include <string.h>
using namespace std;

# define MAX 4001
int dp[MAX][MAX];
string s1,s2;


int main() {
    cin >> s1 >> s2;

    int result = 0;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
    }

    cout << result << endl;
}