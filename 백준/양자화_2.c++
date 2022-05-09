#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
# define INF 987654321
int n;
int A[101], pSum[101], pSqSum[101];
int cache[101][11];

void precalc() {
    sort(A, A+n);
    pSum[0] = A[0];
    pSqSum[0] = A[0]*A[0];

    for (int i = 1; i < n; i++) {
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i]*A[i]; 
    }
    for (int i = 0; i < 101; i++) {
        memset(cache[i], -1, sizeof(int)*11);
    }
}

int minError(int lo, int hi) {
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);

    int m = int(0.5 + (double)sum / (hi-lo+1));

    int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
    return ret;
}


int quantize(int from, int parts) {
    if (from == n) return 0;
    if (parts == 0) return INF;

    int &ret = cache[from][parts];
    if (ret != -1) return ret;
    ret = INF;

    for (int partSize = 1; from + partSize <= n; partSize++) {
        ret = min(ret, minError(from, from + partSize -1) + 
                       quantize(from + partSize, parts -1));
    }
    return ret;
    
}

int main() {
    int T; cin >> T;
    while (T--) {
        int s; cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        precalc();
        cout << quantize(0,s) << "\n";
    }
}