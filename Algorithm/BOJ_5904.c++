#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000000
vector<int> arr;

int find_k(int n) {
    for(int ret=0;ret<arr.size();ret++) {
        if (n <= arr[ret]) return ret;
    }
    return -1;
}

char solve() {
    int n; cin >> n;
    while(1) {
        int k = find_k(n);
        cout << k << endl;

        if (k==0) {
            if (n==1) return 'm';
            else return 'o';
        }

        if (arr[k-1]+1 == n) return 'm';
        else if (arr[k-1]+1 < n && n <= arr[k-1]+k+3) {
            cout << "hqweqwe";
            return 'o';
        }
        else n -= arr[k-1]+k+3;
    }
}

int main() {
    int cnt = 3;
    while(cnt <= MAX) {
        arr.push_back(cnt);
        cnt = cnt*2 + arr.size()+3;
    }
    cout << solve();
}