# include <iostream>
# include <string.h>
using namespace std;

# define MAX 100000
# define MOD 1000000009

int arr[4][MAX+1];

int plus123(int x, int n) {
    if (arr[x][n] != -1) return arr[x][n];

    int cur = 0;
    for (int i = 1; i <=3; i++) {
        if (i == x) continue;
        cur += plus123(i, n-i);
        cur %= MOD;
    }

    arr[x][n] = cur;

    return cur;
}

int main(){
    int T; cin >> T;
    for (int i = 0; i <= 3; i++) {
        memset(arr[i], -1, sizeof(int)*(MAX+1));
    }
    arr[0][1] = 1;
    arr[1][1] = 0;
    arr[2][1] = 1;
    arr[3][1] = 1;

    arr[0][2] = 1;
    arr[1][2] = 1;
    arr[2][2] = 0;
    arr[3][2] = 1;

    arr[0][3] = 3;
    arr[1][3] = 2;
    arr[2][3] = 2;
    arr[3][3] = 2;

    for (int t = 0; t < T; t++) {
        int n; scanf("%d", &n);
        cout << plus123(0,n) << "\n";
    }

}