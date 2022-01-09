# include <iostream>
# include <string.h>
using namespace std;

# define MAX 2000

int leftCard[MAX];
int rightCard[MAX];
int dp[MAX][MAX];
int N;

int find_dp(int left, int right) {
    if (left == N || right == N) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int dump_left = find_dp(left+1, right);

    int dump_all = find_dp(left+1, right+1);
    
    int dump_right = 0;
    if (leftCard[left] > rightCard[right])
        dump_right = rightCard[right] + find_dp(left, right+1);

    int result = 0;
    result = max(dump_left, max(dump_all, dump_right));

    dp[left][right] = result;

    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &leftCard[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &rightCard[i]);

    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    
    cout << find_dp(0,0) << endl;

}
