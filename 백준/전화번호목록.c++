# include <iostream>
# include <vector>
# include <cstdio>
# include <algorithm>
# include <string>
using namespace std;

bool is_prefix(string s1, string s2) {
    if (s1.length() >= s2.length()) return false;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) return false;
    }
    return true;
}

void print_result(const vector<string> &nums) {
    for (int i = 0; i < nums.size()-1; i++) {
        if (is_prefix(nums[i], nums[i+1])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int T; cin >> T;

    for (int t = 0; t < T; t++) {

        vector<string> nums;
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            nums.push_back(s);
        }

        sort(nums.begin(), nums.end());
        print_result(nums);
        
    }
}
