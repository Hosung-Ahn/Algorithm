# include <iostream>
# include <vector>
# include <algorithm>
# include <map>
using namespace std;

vector<vector<int>> A(4,vector<int>());
map<int,int> dp[4];
int N; 

int find_dp(int k, int num) {
    int &ret = dp[k][num];
    if (ret != 0) return ret;

    if (k == 0) return upper_bound(A[0].begin(), A[0].end(), num) - lower_bound(A[0].begin(), A[0].end(), num);

    for (int i = 0; i < N; i++) {
        ret += find_dp(k-1, num - A[k][i]);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        A[0].push_back(a);
        A[1].push_back(b);
        A[2].push_back(c);
        A[3].push_back(d);
    }
    sort(A[0].begin(), A[0].end());
    cout << find_dp(3,0); 
}