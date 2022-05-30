# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 200000
int arr[MAX] = {0,};
int N,C;

bool is_up(int dist) {
    int cnt = 1;
    int cur = arr[0];
    for (int i = 0; i < N; i++){
        if (arr[i] - cur >= dist) {
            cnt++;
            cur = arr[i];
        }
    }
    return cnt >= C;
}

int binary_search() {
    int lo = 1;
    int hi = arr[N-1]-arr[0];

    while (lo != hi) {
        int mid = (lo+hi)/2+1;

        if (is_up(mid)) {
            lo = mid;
        }
        else hi = mid-1;
    }
    return lo;
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);

    cout << binary_search();


}