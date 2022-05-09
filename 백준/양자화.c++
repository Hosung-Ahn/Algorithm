#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
# define MAX 100+1
# define INF 1987654321
# define ll long long

int N,S; 
int square_sum[MAX] = {0,};
int total_sum[MAX] = {0,};
ll dp[MAX][11] = {0,};
vector<int> arr;

ll cal_err(int s, int e, int avg) {
    ll ret = square_sum[e] - square_sum[s-1]
            -(2*avg*(total_sum[e] - total_sum[s-1]))
            +(e-s+1)*avg*avg;
    return ret;
}

int cal_avg(int s, int e) {
    double x = total_sum[e] - total_sum[s-1];
    x /= (e-s+1);
    return round(x);
}

ll find_dp(int s, int d) {
    if (d == S) return cal_err(s,N,cal_avg(s,N));
    if (s == N) return 0; 
    

    ll &ret = dp[s][d];
    if (ret != -1) return ret;

    ret = INF;

    for (int i = s; i < N; i++) {
        ll tmp = cal_err(s,i,cal_avg(s,i)) + find_dp(i+1,d+1);
        ret = min(ret, tmp);
    }
    return ret;
}


void clear() {
    arr.clear();
    for (int i = 0; i < MAX; i++) {
        memset(dp[i], -1, sizeof(ll)*11);
    }
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        clear();
        cin >> N >> S;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());

        int square = 0, total = 0;

        for (int i = 0; i < N; i++) {
            square += arr[i] * arr[i];
            total += arr[i];
            square_sum[i+1] = square;
            total_sum[i+1] = total;
        }

        cout << find_dp(1,1) << "\n";
        
    }
    
}