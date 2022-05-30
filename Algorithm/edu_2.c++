# include <iostream>
using namespace std;

# define MAX 200000+1
# define ll long long
int arr[MAX] = {0,};

int main() {
    int T; cin >> T;
    while (T--) {
        int n,B,x,y; scanf("%d %d %d %d", &n, &B, &x, &y);
        ll result = 0;
        for (int i = 1; i <= n; i++) {
            int cur = arr[i-1] + x;
            if (cur > B) cur = arr[i-1] - y;
            arr[i] = cur;
            result += arr[i];
        }
        cout << result << "\n";
    }
}