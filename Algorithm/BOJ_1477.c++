#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_ok(const vector<int> &load, int x, int M) {
    int cnt = 0;
    for(int l : load) {
        cnt += (l-1)/x;
    }
    return cnt <= M;
}

void binary_search(const vector<int> &load, int M) {
    int lo = 1; int hi = 1000;
    while(lo < hi) {
        int mid = (lo+hi)/2;
        if (is_ok(load, mid, M)) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}

int main() {
    int N,M,end; cin >> N >> M >> end;
    vector<int> arr(N,0);
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> load;
    if (!arr.empty()) load.push_back(arr.front());
    
    for(int i=1;i<arr.size();i++) {
        load.push_back(arr[i]-arr[i-1]);
    }

    load.push_back(end - (arr.empty() ? 0 : arr.back()) );

    binary_search(load, M);
}