#include<iostream>
using namespace std;
#define MAX 500

int arr[MAX] = {0,};
int leftMax[MAX] = {0,};
int rightMax[MAX] = {0,};

int main() {
    int H,W; cin >> H >> W;
    for(int i=0;i<W;i++) {
        cin >> arr[i];
    }
    int t=0;
    for(int i=0;i<W;i++) {
        t = max(t,arr[i]);
        leftMax[i] = t;
    }
    t=0;
    for(int i=W-1;i>=0;i--) {
        t = max(t, arr[i]);
        rightMax[i] = t;
    }
    int ans=0;
    for(int i=0;i<W;i++) {
        ans += min(leftMax[i], rightMax[i])-arr[i];
    }
    cout << ans;
}