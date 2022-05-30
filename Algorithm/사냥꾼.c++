#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,L;
vector<int> animal,human;

bool bi_search(int a,int b) {
    int lo = 0; 
    int hi = M-1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if (human[mid] >= a && human[mid] <= b) return true;
        else if (b < human[mid]) hi = mid-1;
        else lo = mid+1;
    }
    return false;
}

int main() {
    cin >> M >> N >> L;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        human.push_back(x);
    }
    sort(human.begin(), human.end());
    int result = 0;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        if (y > L) continue;
        int a = x - (L-y);
        int b = x + (L-y);
        if (bi_search(a,b)) {
            result++;
        }
    }
    cout << result;
}