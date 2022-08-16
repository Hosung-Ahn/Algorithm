#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void pop_pq(priority_queue<pair<int,int>> &pq) {
    int cur = pq.top().first;
    while(!pq.empty() && pq.top().first == cur) {
        pq.pop();
    }
}

int ans(priority_queue<pair<int,int>> &pq, long long k) {
    vector<int> arr;
    while(!pq.empty()) {
        arr.push_back(pq.top().second);
        pq.pop();
    }
    sort(arr.begin(), arr.end());
    return arr[k];
}


int solution(vector<int> food_times, long long k) {
    k++;
    priority_queue<pair<int,int>> pq;

    for(int i=0;i<food_times.size();i++) {
        pq.push({-food_times[i], i+1});
    }

    int erased_h = 0;

    while(true) {
        long long n = (-pq.top().first - erased_h)*pq.size();
        cout << k << " " << n << endl;
        if (k <= n) {
            k = (k-1)%pq.size();
            cout << "k : " << k << endl;
            return ans(pq, k);
        }
        else {
            erased_h = -pq.top().first;
            pop_pq(pq);
            k -= n;
            if (pq.empty()) return -1;
        }
    }
}

int main() {
    vector<int> arr = {3,1,1,1,1};
    cout << solution(arr, 1);
}