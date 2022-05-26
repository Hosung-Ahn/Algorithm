#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    vector<int> arr;

    while(T--) {
        int N,M; cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr.push_back(x);
        }    
        int sum = 0;
        cin >> M;
        for (int i = 0; i < M; i++) {
            int x; cin >> x;
            sum += x;
            sum %= N;
        }
        cout << arr[sum] << "\n";
        arr.clear();
    }
}
