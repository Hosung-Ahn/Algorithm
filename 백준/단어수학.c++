# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <math.h>
# include <cstdio>

using namespace std;

vector<int> arr(26);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;

    vector<string> nums;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        nums.push_back(s);
    }

    for (string num : nums) {
        for (int i = 0; i < num.size(); i++) {
            arr[num[i] - 65] += pow(10, num.size() - i - 1);
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());

    int result = 0, max_n = 9;

    for (int n : arr) {
        if (n == 0) break;
        result += n * max_n--;
    }
    cout << result;
}