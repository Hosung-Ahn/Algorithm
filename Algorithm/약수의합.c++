# include <iostream>
# include <math.h>
using namespace std;

# define MAX 1000001
# define ll long long

ll arr[MAX] = {0,};


int main() {
    // arr[1] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; i*j < MAX; j++) {
            arr[i*j] += i;
        }
        if (i == MAX-1) continue;
        arr[i+1] += arr[i];
    }

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int x; scanf("%d", &x);
        cout << arr[x] << "\n";
    }

}