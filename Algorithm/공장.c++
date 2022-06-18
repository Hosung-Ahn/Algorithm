#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define MAX 1000001

int num[MAX] = {0,};
vector<int> sorted,arr;
ll result = 0;


void merge(vector<int> &arr, int left, int right) {
    int i = left;
    int mid = (left + right)/2;
    int j = mid+1;
    int k = left;

    while(i <= mid && j <= right) {
        if (num[arr[i]] < num[arr[j]]) {
            sorted[k++] = arr[i++];
        }
        else {
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
    int mid = (right+left)/2;
    merge_sort(arr,left, mid);
    merge_sort(arr,mid+1, right);
    merge(arr,left,right);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    arr.resize(N);
    sorted.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        num[x] = i;
    }
    merge_sort(arr, 0, N-1);
    cout << result;

}