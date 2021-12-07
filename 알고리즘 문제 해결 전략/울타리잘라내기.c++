# include <iostream>
# include <vector>
using namespace std; 

vector<int> h;

int solve(int left, int right){
    if (left == right) return h[left];

    int mid = (left + right) / 2;

    int ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;

    int height = min(h[lo], h[hi]);

    ret = max(ret, height* 2);
    while (left < lo || right > hi) {
        if (right > hi && (h[lo-1] < h[hi + 1] || lo == left) ) {
            hi++;
            height = min(h[hi], height);
        }
        else {
            lo--;
            height = min(h[lo], height);
        }
        ret = max(ret, (hi - lo + 1)*height);
    }
    return ret;
}

int main(){
    int n; cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        h.push_back(x);
    }

    cout << solve(0, n-1) << endl;
    
}