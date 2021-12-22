    # include <iostream>
    using namespace std;

    # define MAX 1000001
    # define MOD 1000000009

    int arr[MAX] = {0,};

    int find_cal(int n) {
        if (arr[n] != 0) return arr[n];

        int result = 0;

        for (int i = 1; i <= 3; i++) {
            result += find_cal(n-i);
            result %= MOD;
        }

        arr[n] = result;

        return result;
    }

    int main() {
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;

        int T; cin >> T;
        for (int t = 0; t < T; t++) {
            int n; scanf("%d", &n);

            printf("%d\n", find_cal(n));
        }
    }