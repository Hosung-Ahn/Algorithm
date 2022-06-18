#include <iostream>
using namespace std;
#define MAX 10001
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        int result = 0;
        bool arr[MAX] = {0,};
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            if (arr[x]) continue;
            arr[x] = true;
            result++;
        }
        if ((N-result) % 2 != 0) result--;
        cout << result << "\n";
    }
}