# include <iostream>
# include <vector>
# include <math.h>
# include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; t++) {

        vector<int> arr; 
        int N; cin >> N;
        for(int i = 0; i < N; i++) {
            int x; scanf("%d", &x);
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end(), greater<int>());

        int left = arr[0];
        int right = arr[0];

        int result = 0;

        for (int i = 1; i < arr.size(); i++) {
            int diff;
            if (i % 2 == 1) {
                diff = left - arr[i];
                left = arr[i];
            }
            else {
                diff = right - arr[i];
                right = arr[i];
            }
            result = max(result, diff);
        }

        cout << max(result, abs(left - right)) << "\n";
    }
}