#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> stations;
priority_queue<int> pq;
int N, L, P; 



void solve() {
    int ans = 0;
    while(!stations.empty() && stations.top().first <= P) {
        pq.push(stations.top().second);
        stations.pop();
    }
    while(P < L) {
        if (pq.empty()) {
            cout << -1;
            return;
        }
        P += pq.top();
        pq.pop();
        ans++;
        while(!stations.empty() && stations.top().first <= P) {
            pq.push(stations.top().second);
            stations.pop();
        }
    }
    cout << ans;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        stations.push({a,b});
    }
    cin >> L >> P;
    solve();
}