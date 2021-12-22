# include <iostream>

using namespace std;

# define MAX 100000

int arr[MAX];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i-1] >= 0) arr[i] += arr[i-1];

        if (arr[i] > result) result = arr[i];
    }

    cout << result << endl;
}