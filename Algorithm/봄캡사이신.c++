# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 300000
# define MOD 1000000007
# define ll long long

ll E2[MAX] = {0,};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    E2[0] = 1;
    for (int i = 1; i < MAX; i++) {
        E2[i] = (E2[i-1]*2) % MOD;
    }

    vector<int> arr;
    int N; cin >> N;
    // int N = MAX-7;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    ll result = 0;
    for (int i = 0; i < N; i++) {
        result += (arr[i] * (E2[i] - E2[N-1-i] + MOD) ) % MOD;
        result %= MOD;
    }
    cout << result;

}