#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> arr;
int N; 

int main() {
    cin>>N;
    for (int i=0;i<N;i++) {
        int x; cin>>x;
        arr.push_back({x,i});
    }
    sort(arr.begin(), arr.end());

    // 버블소트에서 저번 텀에 움직이지 않은 노드는 이번 텀에 절대 움직일 수 없다.
    // 저번 텀에 움직이지 않았다 => 저번 텀에 나보다 큰 값이 내 앞에 없었다.
    // 저번 텀의 결과 큰 값은 뒤로만 움직인다. 따라서 이번 텀에도 나보다 큰 값은 내 앞에 없다.
    // 따라서 저번 텀에 움직이지 않은 노드는 반드시 이번 텀에도 움직이지 않는다.

    // 따라서 버블 소트가 진행된 텀의 수는 각각 노드가 움직인 거리들의 최대값이다.
    int ans = 0;
    for (int i=0;i<N;i++) {
        int tmp = arr[i].second-i;
        ans = max(tmp, ans);
    }
    cout << ans+1;
}