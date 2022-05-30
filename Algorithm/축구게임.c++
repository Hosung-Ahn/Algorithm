# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> arr;
int n; 

int nC2(int n) {
    return n*(n-1)/2;
}

void solve() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < nC2(i+1)) {
            cout << -1;
            return;
        }
    }
    if (sum != nC2(n)) {
        cout << -1;
        return;
    }
    cout << 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());\
    
    solve();
}