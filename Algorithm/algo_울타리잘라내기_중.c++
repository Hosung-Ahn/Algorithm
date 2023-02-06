#include <iostream>
#include <queue>
using namespace std; 
#define MAX 20000
int N;
int h[MAX] = {0,};

int cal_cur(int idx, int lo, int hi) {
    int ret = h[idx];
    int total_w = 1;
    int total_h = h[idx];

    int left = idx;
    int right = idx;
    while(left > lo || right < hi) {
        total_w++;
        if (left == lo) total_h = min(total_h, h[++right]);
        else if (right == hi) total_h = min(total_h, h[--left]);
        else {
            if (h[left-1] < h[right+1]) total_h = min(total_h, h[++right]);
            else total_h = min(total_h, h[--left]);
        }

        ret = max(ret, total_w*total_h);
    }
    return ret;
}

int dc(int lo, int hi) {
    if (lo > hi) return 0;
    if (lo == hi) return h[lo];

    int mid = (lo+hi)/2;

    int cur = cal_cur(mid, lo, hi);
    int left = dc(lo, mid-1);
    int right = dc(mid+1, hi);

    return max(cur, max(left, right));
}

void solve() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> h[i];
    cout << dc(0, N-1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }   
}