#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> arr;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        arr.push_back({x,y});
    }

    sort(arr.begin(), arr.end());

    int s = arr[0].first;
    int e = arr[0].second;
    int result = 0;
    for (int i = 1; i < N; i++) {
        int cs = arr[i].first;
        int ce = arr[i].second;
        if (cs <= e) {
            e = max(e, ce);
        }
        else {
            result += e-s;
            s = cs;
            e = ce;
        }
    }
    result += e-s;

    cout << result << endl;
}