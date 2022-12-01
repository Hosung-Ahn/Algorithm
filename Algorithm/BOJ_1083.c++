#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

int max_idx(int s, int e) {
    int max_val = 0;
    int ret = 0;
    for(int i=s;i<=e;i++) {
        if (arr[i] > max_val) {
            ret = i;
            max_val = arr[i];
        }
    }
    return ret;
}

void solve() {
    int N,k; cin >> N;
    arr.resize(N);
    for(int i=0;i<N;i++) cin >> arr[i];
    cin >> k;

    for(int i=0;i<N;i++) {
        int idx = max_idx(i,min(N-1,i+k));
        int x = arr[idx];
        arr.erase(arr.begin()+idx);
        arr.insert(arr.begin()+i, x);
        k-=idx-i;
    }
    for (int a : arr) cout << a << " ";
}

int main() {
    solve();
}