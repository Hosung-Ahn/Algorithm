# include <iostream>
# include <string>
# include <string.h>

using namespace std;
# define MAX 1000

string s1, s2, s3;
int dp[MAX][MAX];

int find_dp(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int result = 0;
    if (s1[i] == s2[j]) 
        result = 1 + find_dp(i-1, j-1);
    else {
        result += max(find_dp(i-1, j), find_dp(i,j-1));
    }

    dp[i][j] = result;

    return result;
}

void myPrint(int i, int j) {
    if (i < 0) return;
    if (j < 0) return;

    if (dp[i][j] == dp[i-1][j]) myPrint(i-1,j);
    else if (dp[i][j] == dp[i][j-1]) myPrint(i,j-1);
    else { 
        s3.push_back(s1[i]);
        myPrint(i-1,j-1);
    }
    
}

int main() {
    cin >> s1 >> s2;

    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    int i = s1.size() - 1;
    int j = s2.size() - 1;
    cout << find_dp(i,j) << endl;

    myPrint(i,j);

    string::reverse_iterator iter;

    for (iter = s3.rbegin(); iter != s3.rend(); iter++)
        cout << *iter;

}