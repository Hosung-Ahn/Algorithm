#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int X,N;

void solution() {
    int lo = 0;
    int hi = N-1;
    while (lo < hi) {
        int sum = arr[lo] + arr[hi];
        if (sum == X) {
            cout << "yes " << arr[lo] << " " << arr[hi] << "\n";
            return;
        }
        if (sum > X) hi--;
        else lo++;
    }
    cout << "danger\n";
}

int main() {

    while(cin >> X) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr.push_back(x);
        } 

        sort(arr.begin(), arr.end());
        for (int i = 0; i < 7; i++) {
            X *= 10;
        }
        solution();
        arr.clear();
    }
}
