# include <iostream>
using namespace std;

# define MAX 1000001
# define MOD 1000000009

int arr[MAX] = {0,};

int find_cal(int n) {
    if (arr[n] != 0) return arr[n];

    int start_1 = arr[n-1] = find_cal(n-1) % MOD;
    int start_2 = arr[n-2] = find_cal(n-2) % MOD;
    int start_3 = arr[n-3] = find_cal(n-3) % MOD;

    arr[n] = (start_1 + start_2 + start_3) % MOD;

    return arr[n];
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