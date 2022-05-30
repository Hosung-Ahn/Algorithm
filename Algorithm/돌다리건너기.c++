# include <iostream>
# include <string>
# include <vector>
# include <string.h>
using namespace std;

int dp[2][100][20];
vector<string> bridges;
string arr;

int find_dp(int side, int stone, int idx) {
    if (idx >= arr.size()) return 1;
    if (stone >= bridges[0].size()) return 0;

    if (dp[side][stone][idx] != -1) return dp[side][stone][idx];

    int result = 0;
    for (int i = stone; i < bridges[0].size(); i++) {
        if (bridges[side][i] == arr[idx]) {
            result += find_dp((side+1)%2, i+1, idx+1);
        }
    }

    dp[side][stone][idx] = result;
    return result;
}

int main() {
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 100; j++)
            memset(dp[i][j], -1, sizeof(int)*20);

    cin >> arr;
    for (int i = 0; i < 2; i++) {
        string s; cin >> s;
        bridges.push_back(s);       
    }

    int result = 0;
    result += find_dp(0,0,0);
    result += find_dp(1,0,0);

    cout << result; 
    


    
}