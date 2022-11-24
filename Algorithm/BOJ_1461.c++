#include <iostream>
#include <queue>
using namespace std;

void pop_n(priority_queue<int> &pq, int n) {
    while(n--) {
        if (pq.empty()) return;
        pq.pop();
    }
}

int main() {
    int N,M; cin >> N >> M;
    priority_queue<int> left, right;

    left.push(0);
    right.push(0);
    
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        if (x > 0) right.push(x);
        else left.push(-x);
    }
    
    int ans = 0;
    if (left.top() < right.top()) {
        ans += right.top();
        pop_n(right, M);
    }
    else {
        ans += left.top();
        pop_n(left, M);
    }

    while(!right.empty()) {
        ans += right.top()*2;
        pop_n(right, M);
    }
    while(!left.empty()) {
        ans += left.top()*2;
        pop_n(left, M);
    }

    cout << ans;
}