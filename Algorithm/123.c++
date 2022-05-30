#include <iostream>
#include <cstring>
using namespace std;

int dp[201][8] = {0,};
int money[] = {1,2,5,10,20,50,100,200};

int find_dp(int n, int k) {
    if (n == 0 || k == 0) return 1;
    int &ret = dp[n][k];
    if (ret != 0) return ret;

    int nn = n;
    int c = 0; 
    for (int nn = n; nn >= 0; nn -= money[k]) {
        ret += find_dp(nn, k-1);
    }
    return ret;
}

int main() {
    cout << find_dp(200,7);
}