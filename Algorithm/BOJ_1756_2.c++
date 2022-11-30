#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
vector<int> arr;
int N,D;

int lower(int lo, int hi, int x) {
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if (arr[mid] < x) lo=mid+1;
        else hi=mid;
    }
    return lo;
}

void solve() {
    int lo=0, hi=D-1;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        lo = lower(lo,hi,x)+1;
        if (lo > hi) {
            cout << 0;
            return;
        }
    }
    cout << D-lo+1;
}

int main() {cin >> D >> N;
    int x = INF;
    for(int i=0;i<D;i++) {
        int d; cin >> d;
        x = min(x, d);
        arr.push_back(x);
    }
    reverse(arr.begin(), arr.end());
    solve();
}