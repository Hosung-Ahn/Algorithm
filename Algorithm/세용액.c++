#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

# define MAX 5000
# define ll long long


ll P[MAX];
int N;
int ans[3];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> P[i];
    
    sort(P, P+N);

    ll minSum = 3000000000+1;

    for (int k = 0; k < N-2; k++) {
        int l = k+1, r = N-1;
        while (l < r) {
            ll sum = P[k] + P[l] + P[r];
            if (abs(sum) < minSum) {
                ans[0] = P[k];
                ans[1] = P[l];
                ans[2] = P[r];
                minSum = abs(sum);
            }

            if (sum > 0) r--;
            else l++;
        }
    }

    sort(ans, ans+3);

    for (int i = 0; i < 3; i++)
        cout << ans[i] << " ";
}
