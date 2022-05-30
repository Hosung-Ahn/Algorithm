# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

vector<pair<int,int>> arr;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N,D; cin >> N; 
    for (int i = 0; i < N; i++) {
        int h,o; cin >> h >> o;
        if (h < o) arr.push_back({h,o});
        else arr.push_back({o,h});
    }
    cin >> D;
    sort(arr.begin(), arr.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    int result = 0;

    for (pair<int,int> x : arr) {
        int xL = x.first;
        int xR = x.second;
        int cur_D = xR-xL;
        if (cur_D > D) continue;
        
        pq.push(xL);

        while(!pq.empty()) {
            if (pq.top() >= xR-D) break;
            pq.pop();
        }
        result = max(result, (int)pq.size());
    }
    cout << result;
}