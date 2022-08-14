#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000

int arr[MAX] = {0,};
int N,M;

int lower(int n) {
    int lo = 0;
    int hi = N-1;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if (arr[mid] < n) lo = mid+1;
        else hi = mid;
    }
    return arr[lo];
}

int upper(int n) {
    int lo = 0;
    int hi = N-1;
    while(lo<hi) {
        int mid = (lo+hi)/2+1;
        if (arr[mid] <= n) lo = mid;
        else hi = mid-1;
    }
    return arr[lo];
}

int main() {
    cin >> N >> M;
    for (int i=0;i<N;i++) cin>>arr[i];
    sort(arr, arr+N);
    
    int ans = 2000000001;
    for (int i=0;i<N;i++) {
        int a = arr[i];
        
        int b = upper(a-M);
        if (a-b >= M) ans = min(ans, a-b);

        b = lower(a+M);
        if (b-a >= M) ans = min(ans, b-a);
    }

    cout << ans;
}