#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
int arr[MAX] = {0,};
int dp[MAX] = {0,};
int dp_1[MAX] = {0,};

int find_dp(const vector<int> &arr, int s, int e) {
    if (e-s == 1) return max(arr[s], arr[e]);
    else if (e-s == 0) return arr[s];
    else if (e-s < 0) return 0;

    int &ret = dp[s];
    if (ret != 0) return ret;

    ret = max(arr[s]+find_dp(arr,s+2,e), find_dp(arr,s+1,e));
    return ret;
}

int find_dp_1(const vector<int> &arr, int s, int e) {
    if (e-s == 1) return max(arr[s], arr[e]);
    else if (e-s == 0) return arr[s];
    else if (e-s < 0) return 0;

    int &ret = dp_1[s];
    if (ret != 0) return ret;

    ret = max(arr[s]+find_dp(arr,s+2,e), find_dp(arr,s+1,e));
    return ret;
}

int solution(vector<int> sticker)
{   
    int e = sticker.size()-1;
    cout << find_dp(sticker,1,e) << endl;
    cout << arr[0] + find_dp(sticker,2,e-1) << endl;
    return max(find_dp(sticker,1,e), arr[0] + find_dp(sticker,2,e-1));
}

int main() {
    vector<int> arr = {5};
    solution(arr);
}