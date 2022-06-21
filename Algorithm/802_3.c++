#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

void solve() {
    int N; cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    int mid = 0;
    for (; mid < N; mid++) {
        if (mid == N-1 || arr[mid] < arr[mid+1]) break;
    }
    ll left = 0, right = 0, result = 0;

    for (int i = mid; i >= 1; i--) {
        if (arr[i] > arr[i-1]) {
            right += arr[i] - arr[i-1];
        }
    }
    for (int i = mid; i < N-1; i++) {
        if (arr[i] > arr[i+1]) {
            left += arr[i] - arr[i+1];
        }
    }
    result += left + right;
    result += left + right - arr[mid];
    if (arr[mid] - left - right >= 0) {
        result += arr.front() + arr.back();
    }
    else {
        result += arr.front() + right - arr[mid];
        result += arr.back() + left - arr[mid];
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}