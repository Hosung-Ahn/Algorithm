#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int arr[MAX] = {0,};
int N;

void LIS() {
    vector<int> size;
    for(int i=0;i<N;i++) {
        int x = arr[i];
        if (size.empty() || size.back() < x) size.push_back(x);
        else {
            vector<int>::iterator iter;
            iter = lower_bound(size.begin(), size.end(), x);
            *iter = x;
        }
    }
    cout << N - size.size();
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    LIS();
}