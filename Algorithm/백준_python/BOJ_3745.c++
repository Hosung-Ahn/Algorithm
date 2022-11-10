#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int arr[MAX];
int N;

void solve() {
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    vector<int> size;
    for(int i=0;i<N;i++) {
        int x = arr[i]; 
        if (size.empty() || size.back() < x) {
            size.push_back(x);
        }
        else {
            vector<int>::iterator iter = upper_bound(size.begin(), size.end(), x);
            *iter = x;
        }
    }
    cout << size.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while(cin >> N) {
        solve();
    }
    // cin >> N;
    // solve();
}   