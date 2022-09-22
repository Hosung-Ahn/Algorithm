#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 500
int dp[MAX][MAX];
int N;

int find_dp(const vector<vector<int>> &arr, int i, int j) {
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    if (i==N) return arr[i][j];

    ret = arr[i][j] + max(find_dp(arr,i+1,j), find_dp(arr,i+1, j+1));
    return ret;

int solution(vector<vector<int>> triangle) {
    for(int i=0;i<MAX;i++) memset(dp[i], -1, sizeof(int)*MAX);
    N = triangle.size()-1;
    return find_dp(triangle,0,0);
}