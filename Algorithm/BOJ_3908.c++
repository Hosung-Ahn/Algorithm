#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;
#define MAX 2000

bool prime[MAX];
vector<int> prime_arr;
int dp[310][15][MAX];

void find_prime() {
    int check = sqrt(MAX);
    for(int i=2;i<=check;i++) if(prime[i]) {
        for(int j=2*i;j<MAX;j+=i) prime[j] = false;
    }
    for(int i=2;i<MAX;i++) if (prime[i]) {
        prime_arr.push_back(i);
    }
}

int find_dp(int idx, int k, int n) {
    int &ret = dp[idx][k][n];
    if (ret != -1) return ret;

    if (k == 0) {
        if (n == 0) return 1;
        return 0;
    }

    ret = 0;
    for(int i=idx;i<prime_arr.size();i++) {
        if (prime_arr[i] > n) break;
        ret += find_dp(i+1, k-1, n-prime_arr[i]); 
    }
    return ret;
}

int main() {
    memset(prime, 1, sizeof(prime));
    memset(dp, -1, sizeof(dp));
    find_prime();
    int T; cin >> T;
    while(T--) {
        int k,n; cin >> n >> k;
        cout << find_dp(0, k, n) << "\n";
    }
}