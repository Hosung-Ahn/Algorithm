# include <iostream>
# include <string.h>
using namespace std;

# define MAX 101

bool arr[MAX] = {0,};
int dp[MAX][MAX];
int N,K;

int find_dp(int day, int cnt) {
    if (day > N) return 0;
    if (arr[day]) return find_dp(day+1, cnt);
    if (dp[day][cnt] != -1) return dp[day][cnt];

    int result = 0;
    result = min(10000 + find_dp(day+1,cnt), 
            min(25000 + find_dp(day+3,cnt+1), 
                37000 + find_dp(day+5, cnt+2)));

    if (cnt >= 3) {
        result = min(result, find_dp(day+1,cnt-3));
    }

    dp[day][cnt] = result;
    return result;
}

int main() {
    cin >> N >> K;
    for(int i = 1; i <= K; i++) {
        int d; scanf("%d", &d);
        arr[d] = true;
    }
    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    cout << find_dp(1,0) << endl;
}