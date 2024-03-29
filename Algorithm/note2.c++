# include <iostream>
#include <vector>
# include <queue>
# include <cmath>
# include <algorithm>
using namespace std;

void lower(vector<int> &arr, int n) {
    int lo = 0;
    int hi = arr.size()-1;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if (arr[mid] < n) lo = mid+1;
        else hi = mid;
    }
    cout << "lower : " << lo << " " << arr[lo] << endl;
}

void upper(vector<int> &arr, int n) {
    int lo = 0;
    int hi = arr.size()-1;
    while(lo<hi) {
        int mid = (lo+hi)/2+1;
        if (arr[mid] <= n) lo = mid;
        else hi = mid-1;
    }
    cout << "upper : " << lo+1 << " " << arr[lo+1] << endl;
}

void normal(vector<int> &arr, int n) {
    int lo = 0;
    int hi = arr.size()-1;
    while(lo < hi) {
        int mid = (lo + hi)/2;
        if (arr[mid] < n) lo = mid+1;
        else if (arr[mid] > n) hi = mid-1;
        else {
            cout << "normal : " << mid << " " << arr[mid] << endl;
            return;
        }
    }
    cout << "normal : " << lo << " " << arr[lo] << endl;
}

int main() {
    vector<int> arr = {1,1,1,3,3,3};
    lower(arr, 2);
    cout << lower_bound(arr.begin(), arr.end(), 2)-arr.begin() << endl;
    upper(arr, 2);
    cout << upper_bound(arr.begin(), arr.end(), 2)-arr.begin() << endl;
    normal(arr, 2);

    vector<int> arr2 = {1,1,2,2,2,3,3};
    lower(arr2, 2);
    cout << lower_bound(arr2.begin(), arr2.end(), 2)-arr2.begin() << endl;
    upper(arr2, 2);
    cout << upper_bound(arr2.begin(), arr2.end(), 2)-arr2.begin() << endl;
    normal(arr2, 2);

    vector<int> arr3 = {1,3,6,10,15,21};
    lower(arr3, 13);
    cout << lower_bound(arr3.begin(), arr3.end(), 13)-arr3.begin() << endl;
    upper(arr3, 2);
    cout << upper_bound(arr3.begin(), arr3.end(), 2)-arr3.begin() << endl;
}