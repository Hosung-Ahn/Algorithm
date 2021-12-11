# include <iostream>
# include <vector>
using namespace std;
#define MAX 1000

int n; 
vector<int> nums;
vector<int> dp;  

int find_last_cnt(int index) {
    int cur = nums[index];

    int ret = 0;
    for (int i = 0; i < index; i++) { 
        if (nums[i] < cur) {
            if (dp[i] > ret) ret = dp[i];
        }
    }
    return ret + 1;
}


int main() {
    int x; cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
        dp.push_back(1);
    }

    int result = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = find_last_cnt(i);
        if (dp[i] > result) result = dp[i];
    }

    cout << result << endl;
}