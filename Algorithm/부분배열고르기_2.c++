#include <iostream>
using namespace std;
#define MAX 100001
#define ll long long
int arr[MAX];
ll sum_arr[MAX];

ll cal(int left, int right) {
    int mid = (left + right)/2 ;
    int lo = mid, hi = mid;
    ll sum = arr[mid];
    int min_num = arr[mid];
    ll ret = 0;

    while (lo >= left && hi <= right) {
        ret = max(ret, sum *min_num);
        if (hi == right) lo--;
        else if (lo == left) hi++;
        else if (arr[lo-1] < arr[hi+1]) hi++;
        else lo--;
        min_num = min(min_num, min(arr[lo], arr[hi]));
        sum = sum_arr[hi] - sum_arr[lo-1];
    }
    return ret;
}

ll daq(int left, int right) {
    if (left == right) return cal(left, right);
    int mid = (left + right)/2;
    ll left_val = daq(left, mid);
    ll right_val = daq(mid+1, right);
    ll cur = cal(left,right);
    // cout << mid << " " << cur << endl;
    return max(left_val, max(right_val, cur));
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) sum_arr[i] = sum_arr[i-1]+arr[i];

    cout << daq(1,N);


}