# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> arr;
    arr.push_back(INT_MIN);

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);

        if (x > arr.back()) {
            arr.push_back(x);
            cnt++;
        }
        else {
            vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), x);
            *iter = x;
        }
    }

    cout << cnt;
}