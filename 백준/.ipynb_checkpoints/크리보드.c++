# include <iostream> 
using namespace std;

# define MAX 100
# define ll long long

ll dp[101];

int main() {
    for (int i = 1; i <= MAX; i++)
        dp[i] = i;

    for (int i = 2; i <= MAX; i++) {
        for (int j = 3; i - j > 0; j++) {
            dp[i] = max(dp[i], dp[i-j] * (j-1));
        }
    }

    for (int i = 1; i <= MAX; i++)
        cout << dp[i] << endl;     
}