#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> S(n,0), E(n,0), AS,AE;
    for (int i = 0; i < n; i++) cin >> S[i]; 
    for (int i = 0; i < n; i++) cin >> E[i];

    for (int i = 0; i < n; i++) {
        if (AS.empty() || S[i] >= AE.back()) {
            AS.push_back(S[i]);
            AE.push_back(E[i]);
        }
        else if (S[i] < AE.back()) {
            if (E[i] <= AE.back()) continue;
            else {
                AS.push_back(AE.back());
                AE.push_back(E[i]);
            }
        }
        cout << AE.back() - AS.back() << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}
