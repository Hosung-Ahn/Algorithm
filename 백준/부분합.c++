# include <iostream>
using namespace std;

# define MAX 100000

int arr[MAX] = {0,};

int main() {
    int N,M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int lo = 0;
    int hi = 0;
    int sum = arr[0];
    int len = N+1;

    while (lo <= hi && hi < N) {
        if (sum < M) {
            sum += arr[++hi];
        }
        else {
            len = min(len, hi-lo+1);
            sum -= arr[lo++];
        }
    }

    if (len == N+1) cout << 0;
    else cout << len;
    
}