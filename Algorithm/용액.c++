#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> arr;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int lo = 0, hi = N-1;
    int ans[2];

    int minSum = 2000000000+1;

    while (lo < hi) {
        int sum = arr[lo] + arr[hi];
        if (abs(sum) < minSum) {
            ans[0] = arr[lo];
            ans[1] = arr[hi];
            minSum = abs(sum);
        }
        if (sum > 0) hi--;
        else lo++;
    }

    cout << ans[0] << " " << ans[1];
}