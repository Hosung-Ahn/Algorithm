# include <iostream> 
# include <math.h>
using namespace std;

# define MAX 100000
# define INF 987654321

int dp[5][5][MAX] = {0,};
int arr[MAX] = {0,};
int N = 0;

int cal_cost(int a, int b) {
    if (a == b) return 1;
    if (a == 0) return 2; 
    if (abs(a-b) == 2) return 4;
    return 3;
}

int find_dp(int a, int b, int idx) {
    if (a != 0 && a == b) return INF;
    if (idx == N) return 0;

    if (dp[a][b][idx] != 0) return dp[a][b][idx];

    int result = INF;
    
    result = min(result, cal_cost(a, arr[idx]) + find_dp(arr[idx],b,idx+1));
    result = min(result, cal_cost(b, arr[idx]) + find_dp(a, arr[idx], idx+1));

    dp[a][b][idx] = result;
    return result;
}

int main() {
    int x;
    while (scanf("%d", &x)) {
        if (x == 0) break;
        arr[N++] = x;
    }
    cout << find_dp(0,0,0);
}
