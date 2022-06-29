#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void solve() {
    int N; cin >> N;
    vector<int> arr(N,0);
    int np = 0,nm = 0,nz = 0;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        if (arr[i] > 0) np++;
        else if (arr[i] < 0) nm++;
        else nz++;
    }
    if (np > 2 || nm > 2) {
        cout << "NO\n";
        return;
    }

    nz = min(nz,3);
    vector<int> rarr;
    for (int i = 0; i < N; i++) if (arr[i] != 0) {
        rarr.push_back(arr[i]);
    }
    for (int i = 0; i < nz; i++) {
        rarr.push_back(0);
    }
    int s = rarr.size();
    for(int i = 0; i < s; i++) for(int j = i+1; j < s; j++) for(int k = j+1; k < s; k++) {
        ll sum = (ll)rarr[i] + rarr[j] + rarr[k];
        bool ck = false;
        for (int l = 0; l < s; l++) {
            if (sum == rarr[l]) {
                ck = true;
                break;
            }
        }
        if (!ck) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}