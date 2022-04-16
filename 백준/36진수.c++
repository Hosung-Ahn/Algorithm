# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <math.h>
# include <iomanip>
using namespace std;

vector<int> result(100,0);
vector<int> tmp1(100,0);
vector<int> tmp2(100,0);

class INT_36 {
public :
    int arr[50] = {0,};
    int num;
    INT_36(int n) : num(n) {}

    void plus_plus(int digit) {
        arr[digit]++;
    }
};

int to_int(char n) {
    if (n >= '0' && n <= '9') return n-48;
    return n-55;
}

char to_36(int n) {
    if (n >= 0 && n <= 9) return n + 48;
    return n + 55;
}

void plus_36(vector<int> &arr, int digit, int n) {
    int a = arr[digit];
    if (a + n > 35) {
        arr[digit] = (a+n) % 36;
        plus_36(arr, digit+1, (a+n)/36);
        return;
    }
    arr[digit]+=n;
}

bool comp(const INT_36 &a1, const INT_36 &a2) {
    for (int i = 0; i < 100; i++) {
        tmp1[i] = 0;
        tmp2[i] = 0;
    }

    for (int i = 0; i < 50; i++) {
        plus_36(tmp1, i, (35 - a1.num) * a1.arr[i]);
    }
    for (int i = 0; i < 50; i++) {
        plus_36(tmp2, i, (35 - a2.num) * a2.arr[i]); 
    }

    for (int i = 99; i >= 0; i--) { 
        if (tmp1[i] == tmp2[i]) continue;
        return tmp1[i] > tmp2[i];
    }
    return false;
}

int main() {
    vector<INT_36> nums;
    for (int i = 0; i < 36; i++) {
        nums.push_back(INT_36(i));
    }
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int digit = s.size()-j-1;
            int num = to_int(s[j]);
            nums[num].plus_plus(digit);
        }
    }
    

    sort(nums.begin(), nums.end(), comp);
    

    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        nums[i].num = 35;
    }

    for (INT_36 num : nums) {
        for (int i = 0; i < 50; i++) {
            plus_36(result, i, num.arr[i]*num.num);
        }
    }

    int start = result.size()-1;
    while (result[start] == 0) {
        start--;
    }

    bool flag = false;
    for (int i = start; i >= 0; i--) {
        flag = true;
        cout << to_36(result[i]);
    }

    if(!flag) cout << 0;
}