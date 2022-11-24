#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
bool day_work[MAX] = {0,};
int N; 
vector<pair<int,int>> arr;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    return a.second > b.second;
}

int find_idx(int idx) {
    for(int i=idx;i>=1;i--) {
        if (!day_work[i]) return i;
    }
    return -1;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int d,v; cin >> d >> v;
        arr.push_back({d,v});
    }
    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;

    for (auto p : arr) {
        int idx = find_idx(p.first);
        if (idx != -1) {
            day_work[idx] = true;
            ans += p.second; 
        }
    }

    cout << ans;
}