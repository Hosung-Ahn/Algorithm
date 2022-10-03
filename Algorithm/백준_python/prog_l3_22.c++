#include <string>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100
#define MOD 1000000007
int R,C;
int dp[MAX][MAX];
bool water[MAX][MAX] = {0,};

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>=C) return false;
    return true;
}

int find_dp(int r, int c) {
    if (r==0 && c==0) return 1;
    if (!in_range(r,c) || water[r][c]) return 0;
    int &ret = dp[r][c];
    if (ret != -1) return ret;
    ret = find_dp(r-1,c) + find_dp(r,c-1);
    ret %= MOD;
    return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    R = n;
    C = m;
    for(int i=0;i<MAX;i++) memset(dp[i], -1, sizeof(int)*MAX);

    for (int i=0;i<puddles.size();i++) {
        int r = puddles[i][1]-1;
        int c = puddles[i][0]-1;
        water[r][c] = true;
    }

    return find_dp(n-1, m-1);
}