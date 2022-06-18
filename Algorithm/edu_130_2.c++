#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector<int> arr;
vector<ll> sum;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N,q; cin >> N >> q;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    sum.push_back(0);
    for (int i = 1; i <= N; i++) {
        sum.push_back(sum[i-1] + arr[i-1]);
    }

    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        ll result = sum[x] - sum[x-y];
        cout << result << "\n";
    }
}