#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int l = 0, r = 0, sum = arr[0], ans = 0;
    while (r < N) {
        if (sum == M) ans++;

        if (sum > M && l < r) sum -= arr[l++];
        else sum += arr[++r];
    }
    cout << ans;
}