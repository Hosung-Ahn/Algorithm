#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T; 
    while(T--) {
        int N,M; cin >> N >> M; 
        vector<pair<int,int>> arr;
        for (int i = 0; i < M; i++) {
            int a,b; cin >> a >> b;
            arr.push_back({b,a});
        }
        sort(arr.begin(), arr.end());

        int book = 1, cnt = 0;
        for (int i = 0; i < M; i++) {
            int b = arr[i].first;
            int a = arr[i].second;
            book = max(book, a);
            if (book <= b) {
                book++;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}