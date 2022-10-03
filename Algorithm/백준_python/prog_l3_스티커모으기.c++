#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 100000
int dp[MAX];

int find_dp(const vector<int> &sticker, int s) {
    int &ret = dp[s];
    if (ret != -1) return ret;
    int l = sticker.size()-s;
    if (l<=0) return 0;
    if (l==1) return sticker[s];
    ret = max(sticker[s]+find_dp(sticker,s+2), find_dp(sticker,s+1));
    return ret;
}

int solution(vector<int> sticker)
{
    memset(dp, -1, sizeof(int)*MAX);
    int zero_out = find_dp(sticker, 1);
    int zero_in = sticker[0];
    if (sticker.size() > 1) {
        sticker.pop_back();
        memset(dp, -1, sizeof(int)*MAX);
        zero_in += find_dp(sticker, 2);
    }
    return max(zero_out, zero_in);
}