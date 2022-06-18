#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<pair<int,int>> arr;

    for (int i = 0; i < N; i++) {
        int s,e; cin >> s >> e;
        arr.push_back({s,e});
    }

    sort(arr.begin(), arr.end(), cmp);

    int start = -1;
    int result = 0;

    for (const pair<int,int> &time : arr) {
        if (time.first < start) continue;
        result ++;
        start = time.second;
    }

    cout << result;

}