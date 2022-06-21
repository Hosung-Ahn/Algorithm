#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int,int>> arr;
vector<int> tmp, tmp_idx, result;

void LIS() {
    tmp.push_back(987654321);

    for (int i = 0; i < arr.size(); i++) {
        int cur = arr[i].second;
        if (tmp.back() > cur) {
            auto iter = lower_bound(tmp.begin(), tmp.end(), cur);
            *iter = cur;
            tmp_idx.push_back(iter - tmp.begin());
        }
        else {
            tmp.push_back(cur);
            tmp_idx.push_back(tmp.size()-1);
        }
    }

    int cnt = tmp.size();
    cout << N-cnt << "\n";

    for (int i = tmp_idx.size()-1; i >= 0; i--) {
        if (tmp_idx[i] != cnt-1) continue;
        cnt--;
        tmp_idx[i] = -1;
    }
    for (int i = 0; i < tmp_idx.size(); i++) {
        if (tmp_idx[i] == -1) continue;
        cout << arr[i].first << "\n";
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(), arr.end());

    LIS();
}