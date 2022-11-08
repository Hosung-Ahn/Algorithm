#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
int N,M;
vector<int> arr;

void find_part(int idx, int end, vector<int> &part, ll sum) {
    if (idx == end) {
        part.push_back(sum);
        return;
    }
    find_part(idx+1, end, part, sum); 
    find_part(idx+1, end, part, sum+arr[idx]);
}

int main() {
    cin >> N >> M;
    arr.resize(N,0);
    for(int i=0;i<N;i++) cin >> arr[i];
    vector<int> part1, part2;
    find_part(0, N/2, part1, 0);
    find_part(N/2, N, part2, 0);

    sort(part2.begin(), part2.end());

    for(auto x : part1) {
        cout << x << " ";
    }
    cout << endl;

    for(auto x : part2) {
        cout << x << " ";
    }
    cout << endl;

    int ans = 0;

    for(auto x : part1) {
        ans += upper_bound(part2.begin(), part2.end(), M-x) - part2.begin();
    }
    cout << ans;
}