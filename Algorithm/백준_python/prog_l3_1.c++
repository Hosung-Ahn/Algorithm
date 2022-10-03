#include <iostream>


#include <vector>
#include <cstring>

using namespace std;

#define MAX 500
int MOD = 20170805;
int R,C;
int dp[MAX][MAX];

bool in_range(int r, int c) {
    if (r<0 || r>=R || c<0 || c>= C) return false;
    return true;
}

int find_dp(int r, int c, int d, const vector<vector<int>> &board) {
    if (r==0 && c==0) return 1;
    if (!in_range(r,c) || board[r][c] == 1) return 0;
    if (board[r][c] == 2) {
        return (d==0 ? find_dp(r,c-1,d, board) : find_dp(r-1,c,d, board));
    }
    int &ret = dp[r][c];
    if (ret != -1) return ret;

    ret = find_dp(r,c-1,0, board) + find_dp(r-1, c,1, board);
    ret %= MOD;
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    R = m;
    C = n;
    for(int i=0;i<MAX;i++) memset(dp[i], -1, sizeof(int)*MAX);
    return find_dp(m-1, n-1, 0, city_map);
}
