# include <iostream> 
using namespace std;

# define MAX 31
# define ll long long

ll dp[MAX][MAX] ={0,};

ll find_dp(int one, int half) {
    if (one == 0 && half == 1) return 1;
    if (one < 0 || half < 0) return 0;
    if (dp[one][half] != 0) return dp[one][half];

    ll result = find_dp(one - 1, half + 1) + find_dp(one, half - 1);
    dp[one][half] = result;

    return result;
}

int main() {
    int n; scanf("%d", &n);
    while (n != 0) {  
        cout << find_dp(n,0) << "\n";
        scanf("%d", &n);
    }
}