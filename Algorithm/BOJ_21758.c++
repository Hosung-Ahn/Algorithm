#include <iostream>
using namespace std;
#define MAX 100001
int arr[MAX];
int sum[MAX] = {0,};
int N;

void solve() {
    int ans = 0;
    int start = sum[N]-sum[1];
    for(int i=2;i<N;i++) {
        int tmp = start - arr[i] + (sum[N]-sum[i]);
        ans = max(ans, tmp);
    }
    start = sum[N-1];
    for(int i=N-1;i>1;i--) {
        int tmp = start - arr[i] + (sum[i-1]);
        ans = max(ans, tmp);
    }
    for(int i=2;i<N;i++) {
        int tmp = sum[i]-sum[1] + sum[N-1]-sum[i-1];
        ans = max(ans, tmp);
    }
    cout << ans;
}

int main() {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> arr[i];
    for(int i=1;i<=N;i++) {
        sum[i] = sum[i-1] + arr[i];
    }
    solve();
}