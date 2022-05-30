#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long
ll MAX_TIME = LLONG_MAX;

vector<int> arr;
int N,M;

bool count(ll m) {
    ll ret = 0;
    for (int i = 0; i < N; i++) {
        ret += m/arr[i];
        if (ret >= M) return false;
    }
    return true;
}

void binary_search() {
    ll lo = 0;
    ll hi = MAX_TIME;

    while (lo < hi) {
        ll mid = (lo+hi)/2;
        if (count(mid)) lo = mid + 1;
        else hi = mid;
    }
    cout << lo;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    binary_search();
}