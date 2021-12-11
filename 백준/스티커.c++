# include <iostream>
# include <vector>
# include <cstdio>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin>> T;
    for (int t = 0; t < T; t++) {
        vector<int> nums[2];
        int n,x; cin >> n;
        nums[0].push_back(0);
        nums[1].push_back(0);
        for (int i = 0; i < n; i++) {
            cin >> x; 
            nums[0].push_back(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            nums[1].push_back(x);
        }

        for (int i = 2; i <= n; i++) {
            nums[0][i] += max(nums[1][i-1], max(nums[0][i-2], nums[1][i-2]));
            nums[1][i] += max(nums[0][i-1], max(nums[0][i-2], nums[1][i-2]));
        }

        cout << max(nums[0][n], nums[1][n]) << endl;
    }
}