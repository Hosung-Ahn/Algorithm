#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

vector<int> arr;
vector<ll> two_sum;


bool binary_search(int x) {
    int lo = 0, hi = two_sum.size()-1;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if (two_sum[mid] == x) return true;
        else if (two_sum[mid] < x) lo = mid+1;
        else hi = mid-1;
    }
    return false;
}

void solve() {
    for(int i=arr.size()-1;i>=0;i--) {
        for(int j=0;j<i;j++) {
            int x = arr[i]-arr[j];
            if (binary_search(x)) {
                cout << arr[i];
                return;
            }
        }
    }
}

int main() {
    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    for(int i=0;i<N;i++) for(int j=i;j<N;j++) {
        two_sum.push_back((ll)arr[i]+arr[j]);
    }

    sort(arr.begin(), arr.end());
    sort(two_sum.begin(), two_sum.end());

    solve();
}