#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define MAX 40001
# define INF 987564321

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    vector<int> size,inputIndex,arr,result;
    arr.resize(N);

    for (int i = 0; i < N; i++) 
        cin >> arr[i];

    size.push_back(INF);

    for (int i = 0; i < N; i++) {
        if (size.back() < arr[i]) {
            size.push_back(arr[i]);
            inputIndex.push_back(size.size()-1);
        }
        else {
            vector<int>::iterator iter = lower_bound(size.begin(), size.end(), arr[i]);
            *iter = arr[i];
            inputIndex.push_back(iter - size.begin());
        }
    }
    cout << size.size() << "\n";
    // cout << "len : " << size.size() << "\n";
    // cout << "arr : ";
    int K = size.size()-1;
    for (int i = N-1; i >= 0; i--) {
        if (inputIndex[i] == K) {
            result.push_back(arr[i]);
            K--;
        }
    }
    for (int i = result.size()-1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}