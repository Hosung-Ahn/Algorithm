#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
int ans = INF;

int Clock[16] = {0,};
vector<vector<int>> btn = {
    {0,1,2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15}, 
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

bool is_all() {
    for(int i=0;i<16;i++) {
        if (Clock[i] != 3) return false;
    }
    return true;
}

void brute(int idx, int tmp) {
    if (is_all()) {
        ans = min(ans, tmp);
        return;
    }

    if (idx == 10) return;

    brute(idx+1, tmp);

    for(int k=1;k<=3;k++) {
        for(int i : btn[idx]) {
            Clock[i]++;
            Clock[i]%=4;
        }
        brute(idx+1, tmp+k);
    }

    for(int i : btn[idx]) {
        Clock[i]++;
        Clock[i]%=4;
    }
}

void solve() {
    for(int i=0;i<16;i++) {
        int x; cin >> x;
        x = x/3-1;
        Clock[i] = x;
    }
    ans = INF;
    brute(0,0);
    cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}