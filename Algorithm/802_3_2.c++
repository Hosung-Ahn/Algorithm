#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    ll left = 0, right = 0, result = 0;
    for (int i = 0; i < N-1; i++) {
        if (arr[i] > arr[i+1]) left += arr[i]-arr[i+1];
        else right += arr[i+1]-arr[i];
    }
    result = left + right + abs(arr[0]-left);
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