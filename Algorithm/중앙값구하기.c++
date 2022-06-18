#include<iostream>
#include<set>
using namespace std;

int arr[10000];

void solution() {
    multiset<int> s;
    int N; cin >> N;
    int a; cin >> a;
    s.insert(a);
    auto mid = s.begin();
    int cnt = 1;
    arr[0] = *mid;
    int mid_idx = 1;

    for (int i = 2; i <= N; i++) {
        cin >> a; s.insert(a);
        if (a >= *mid) {
            while (mid_idx < (i+1)/2) {
                mid++;
                mid_idx++;
            }
        }
        else {
            mid_idx++;
            while (mid_idx > (i+1)/2) {
                mid_idx--;
                mid--;
            }
        }
        if (i%2 == 1) arr[cnt++] = *mid;  
    }

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << arr[i] << " ";
        if (i % 10 == 9) cout << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while(T--){
        solution();
    }  
}