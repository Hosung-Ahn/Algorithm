#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<int> sorted,arr;
ll result = 0;

void merge(vector<int> &arr, int left, int right) {
    int mid = (left+right)/2;
    int i = left;
    int j = mid+1;
    int k = left;

    while(i <= mid && j <= right) {
        if (arr[i] <= arr[j]) 
            sorted[k++] = arr[i++];
        else{
            result += j-k;
            sorted[k++] = arr[j++];
        }
    }

    if (i <= mid) {
        while (i <= mid) {
            sorted[k++] = arr[i++];
        }
    }
    else {
        while (j <= right) {
            sorted[k++] = arr[j++];
        }
    }

    for (int idx = left; idx <= right; idx++) {
        arr[idx] = sorted[idx];
    }
}

void merge_sort(vector<int> &arr, int left, int right) {
    if (left >= right) return;
    int mid = (left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, right);
}

int main() {
    int N; cin >> N;
    sorted.resize(N);
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    merge_sort(arr,0,N-1);
    
    cout << result;
}