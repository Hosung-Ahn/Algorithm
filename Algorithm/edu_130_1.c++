#include<iostream>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int N,M; cin >> N >> M;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            sum += x;
        }
        cout << max(sum-M, 0) << "\n";
    }
}