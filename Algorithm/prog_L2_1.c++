#include <string>
#include <vector>

using namespace std;

bool ok(int n, int k) {
    return (n- (k-1)*k/2) % k == 0;
}

int solution(int n) {
    int ans = 0;
    for(int k=1;k<150;k++) {
        if ((k*(k+1))/2 > n) break;
        if (ok(n, k)) ans++;
    }
    return ans;
}