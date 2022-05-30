# include <iostream>
using namespace std;

# define MAX 1000

int dp[10][MAX+1];

int find_dp(int first, int n) {
    if (n == 1) {
        if ( first < 0 || first > 9 ) return 0;
        else return 1;
    }

    int result = 0;
    result += find_dp(first-1, n-1);
    result += find_dp(first+1, n-1);

    return result;
}


int main() {
    int n; cin >> n;
    int result = 0;
    for (int i = 1; i <= 9; i++){
        result += find_dp(i,n);
    }

    cout << result << endl;
}