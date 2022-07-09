#include<iostream>
#include<vector>
using namespace std;
bool ok = true;

void binary_search(int l, int r, const vector<int> &arr) {
    if (l == r) return;
    int mid = (l+r)/2;

    binary_search(l,mid,arr);
    binary_search(mid+1,r,arr);

    int al = mid-1, ar = mid+1;
    int mn = arr[mid], sum = arr[mid];
    while (al >= l && ar <= r) {
        if (arr[al] > arr[ar]) {
            mn = max(mn, arr[al]);
            sum += arr[al];
            al--;
        }
        else {
            mn = max(mn, arr[ar]);
            sum += arr[ar];
            ar++;
        }
        if (mn < sum) ok = false;
    }

    while (al >= l) {
        mn = max(mn, arr[al]);
        sum += arr[al];
        al--;

        if (mn < sum) ok = false;
    }

    while (ar <= r) {
        mn = max(mn, arr[ar]);
        sum += arr[ar];
        ar++;

        if (mn < sum) ok = false;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ok = true;
    binary_search(0,n-1, arr);
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
