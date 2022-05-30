# include <iostream>
# include <vector>
using namespace std;
# define ll long long

vector<int> num;
vector<ll> nums;


ll to_int(const vector<int> &num) {
    if (num.size() > 10) return -1;
    ll ret = 0;
    for (int i = num.size()-1; i>=0; i--) {
        ret *= 10;
        ret += num[i];
    }
    return ret;
}

void plus_1(int digit) {
    if(num.size()>10) return;

    if (digit+1 < num.size()) {
        num[digit]++;
        if (num[digit] >= num[digit+1] || num[digit] == 10) {
            num[digit] = 0;
            plus_1(digit+1);
        }
        return;
    }
    else if (digit+1 > num.size()) {
        num.push_back(1);
        return;
    }
    else {
        num[digit]++;
        if (num[digit] == 10) {
            num [digit] = 0;
            plus_1(digit+1);
        }
        return;
    }
}

bool is_descending() {
    if (num.size() <= 1 || num.size() > 10) return true;
    for (int i = 1; i < num.size(); i++) {
        if (num[i-1] >= num[i]) return false;
    }
    return true;
}



int main() {
    nums.push_back(0);
    for (int i = 1; i <= 1000000; i++) {
        plus_1(0);
        if (!is_descending()) continue;
        nums.push_back(to_int(num));
    }
    int n; cin >> n;
    if (n >= nums.size()) cout << -1;
    else cout << nums[n];
}