#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> inSet, outSet;
vector<int> arr;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N,M; cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        inSet.push(arr[i]);

        int erased = i - M;
        if (erased >= 0) {
            outSet.push(arr[erased]);
        }
        while(!outSet.empty() && inSet.top() == outSet.top()) {
            inSet.pop();
            outSet.pop();
        }
        cout << inSet.top() << " ";
    }
}